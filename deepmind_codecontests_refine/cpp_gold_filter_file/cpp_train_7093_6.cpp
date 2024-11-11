#include <bits/stdc++.h>
using namespace std;
const int N = 5010, P = 37, M = 1e9 + 207;
int h[N], p[N];
int hs(int l, int r) {
  int prv = ((l ? h[l - 1] : 0) * 1LL * p[r - l + 1]) % M;
  return (h[r] + M - prv) % M;
}
map<int, int> all;
int f[N];
char can[N][N];
int main() {
  p[0] = 1;
  for (int i = 1; i < N; ++i) p[i] = (p[i - 1] * 1LL * P) % M;
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) h[i] = ((i ? h[i - 1] : 0) * 1LL * P + s[i]) % M;
  for (int i = 0; i < n; ++i) f[i] = (i + 1) * a;
  f[0] = a;
  for (int len = 1; len <= n; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int H = hs(i, i + len - 1);
      auto it = all.find(H);
      if (it == all.end())
        all[H] = i + len - 1;
      else {
        int x = it->second;
        if (i > x) can[i][i + len - 1] = 1;
      }
    }
    all.clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    f[i + 1] = min(f[i + 1], f[i] + a);
    int l = 1, r = n - i;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (can[i + 1][i + mid])
        l = mid + 1;
      else
        r = mid;
    }
    for (int j = i + 1; j < i + l; ++j) f[j] = min(f[j], f[i] + b);
  }
  cout << f[n - 1];
}
