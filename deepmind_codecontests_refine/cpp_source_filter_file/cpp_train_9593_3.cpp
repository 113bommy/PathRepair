#include <bits/stdc++.h>
using namespace std;
const int max_m = 1e7 + 10, max_n = 1e5 + 10;
vector<int> pr[max_n], com, que[max_n], ans;
int p[max_m], a[max_n], lb[max_n], rb[max_n], cnt[max_m], num[max_n],
    sign[max_n];
bool check[max_n];
int get(int i) {
  num[0] = sign[0] = 1;
  for (int j = 0; j < (int)pr[i].size(); j++) num[1 << j] = pr[i][j];
  int c = 0;
  for (int mask = 0; mask < (1 << (int)pr[i].size()); mask++) {
    num[mask] = num[mask ^ ((mask) & (-(mask)))] * num[((mask) & (-(mask)))];
    if (mask) sign[mask] = sign[mask ^ ((mask) & (-(mask)))] * -1;
    c += sign[mask] * cnt[num[mask]];
  }
  return c;
}
void addto(int i) {
  num[0] = 1;
  for (int j = 0; j < (int)pr[i].size(); j++) num[1 << j] = pr[i][j];
  for (int mask = 0; mask < (1 << (int)pr[i].size()); mask++) {
    num[mask] = num[mask ^ ((mask) & (-(mask)))] * num[((mask) & (-(mask)))];
    cnt[num[mask]]++;
  }
}
void addans(int i, bool z = false) {
  ans.push_back(i);
  check[i] = true;
  if (z) check[rb[i]] = true;
}
int gcd(int x, int y) { return x == 0 ? y : gcd(y % x, x); }
int main() {
  for (int i = 2; i < max_m; i++)
    if (!p[i]) {
      p[i] = i;
      for (long long j = 1LL * i * i; j < max_m; j += i) p[j] = i;
    }
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int tmp = a[i];
    while (tmp > 1) {
      int tp = p[tmp];
      pr[i].push_back(tp);
      while (tmp % tp == 0) tmp /= tp;
    }
    addto(i);
  }
  int root = -1;
  for (int i = 0; i < n; i++) {
    int tmp = get(i);
    if (tmp == 0)
      com.push_back(i), check[i] = true;
    else if (tmp >= 2)
      root = tmp;
  }
  fill(lb, lb + n, -1);
  fill(rb, rb + n, n - 1);
  bool flag = true;
  while (flag) {
    memset(cnt, 0, sizeof cnt);
    flag = false;
    for (int i = 0; i < n; i++) {
      if (check[i] || rb[i] - lb[i] <= 1) continue;
      flag = true;
      int mb = (rb[i] + lb[i]) / 2;
      que[mb].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      if (!check[i]) addto(i);
      for (auto q : que[i])
        if (get(q))
          rb[q] = i;
        else
          lb[q] = i;
      que[i].clear();
    }
  }
  if ((int)com.size() >= k) ans = com;
  if (k % 2) {
    if (root < 0) {
      ans = com;
      for (int i = 0; i < n; i++)
        if (!check[i]) addans(i, true);
    } else {
      int cnt = 0;
      addans(root);
      for (int i = 0; i < n; i++)
        if (cnt < 2 && gcd(a[i], a[root]) == 1) addans(i), cnt++;
    }
  }
  for (int i = 0; i < n; i++)
    if (!check[i] && !check[rb[i]]) addans(i), addans(rb[i]);
  for (int i = 0; i < n; i++)
    if (!check[i]) addans(i);
  for (int i = 0; i < k; i++) cout << ans[i] + 1 << ' ';
  cout << '\n';
}
