#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
const int maxx = 1e5 + 10;
int prime[maxn], num[maxn], a[maxx], b[maxx];
bool vis[maxn];
int cnt = 0;
void init() {
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) prime[cnt++] = i;
    for (int j = 0; j < cnt && i * prime[j] < maxn; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
void f(int k, int flag) {
  for (int i = 0; i < cnt && prime[i] <= k / prime[i]; i++) {
    if (k % prime[i] == 0) {
      int cnt = 0;
      while (k % prime[i] == 0) k /= prime[i], cnt++;
      num[prime[i]] += flag * cnt;
    }
  }
  if (k != 1) num[k] += flag;
}
int fpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int solve(int k, int flag) {
  int res = 1;
  for (int i = 0; i < cnt && prime[i] <= k / prime[i]; i++) {
    if (k % prime[i] == 0) {
      int cnt = 0;
      while (k % prime[i] == 0) k /= prime[i], cnt++;
      if (flag) {
        int k = min(cnt, max(num[prime[i]], 0));
        res = res * fpow(prime[i], k);
        num[prime[i]] -= k;
      } else {
        int k;
        if (num[prime[i]] >= 0)
          k = 0;
        else
          k = min(cnt, -num[prime[i]]);
        res = res * fpow(prime[i], k);
        num[prime[i]] += k;
      }
    }
  }
  if (k != 1) {
    if (flag) {
      if (num[k] >= 1) res *= k, num[k]--;
    } else {
      if (num[k] <= -1) res *= k, num[k]++;
    }
  }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  init();
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f(a[i], 1);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    f(b[i], -1);
  }
  vector<int> aa, bb;
  for (int i = 1; i <= n; i++) {
    int t = solve(a[i], 1);
    if (t != 1) aa.push_back(t);
  }
  for (int i = 1; i <= m; i++) {
    int t = solve(b[i], 0);
    if (t != 1) bb.push_back(t);
  }
  if (aa.size() == 0) aa.push_back(1);
  if (bb.size() == 0) bb.push_back(1);
  cout << aa.size() << " " << bb.size() << "\n";
  for (int i = 0; i < aa.size(); i++) cout << aa[i] << " ";
  cout << "\n";
  for (int i = 0; i < bb.size(); i++) cout << bb[i] << " ";
  return 0;
}
