#include <bits/stdc++.h>
using namespace std;
int n, m, q, len;
long long a[100005], sum[100005], delta[100005];
int flag[100005];
vector<int> v[100005], pv, cover[100005];
void read() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  for (int i = 1; i <= m; ++i) {
    int k, x;
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }
}
void init() {
  len = (int)sqrt(m * 1.0) + 5;
  for (int i = 1; i <= m; ++i) {
    sum[i] = 0;
    for (auto item : v[i]) {
      sum[i] += item;
      flag[item] = i;
    }
    if (v[i].size() > len) {
      pv.push_back(i);
      cover[i].resize(m + 1);
      for (int j = 1; j <= m; ++j) {
        int cnt = 0;
        for (auto item : v[j]) cnt += flag[item] == i;
        if (cnt > 0) cover[i][j] = cnt;
      }
    }
  }
}
long long query(int k) {
  long long result = 0;
  if (v[k].size() <= len) {
    for (auto i : v[k]) result += a[i];
    for (auto i : pv) result += cover[i][k] * delta[i];
  } else {
    result = sum[k];
  }
  return result;
}
void update(int k, long long pDelta) {
  if (v[k].size() <= len) {
    for (auto i : v[k]) a[i] += pDelta;
  } else {
    delta[k] += pDelta;
  }
  for (auto i : pv) sum[i] += cover[i][k] * pDelta;
}
void solve() {
  char str[10];
  int k, x;
  while (q--) {
    scanf("%s", str);
    if (str[0] == '?') {
      scanf("%d", &k);
      printf("%I64d\n", query(k));
    } else {
      scanf("%d %d", &k, &x);
      update(k, x);
    }
  }
}
int main() {
  read();
  init();
  solve();
  return 0;
}
