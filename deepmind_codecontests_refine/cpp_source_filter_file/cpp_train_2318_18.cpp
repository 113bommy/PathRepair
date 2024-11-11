#include <bits/stdc++.h>
using namespace std;
int Read() {
  int ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) ans += (s[i] - '0') << i;
  return ans;
}
int Update(int s, int i, int j) {
  int a = s & (1 << i), b = s & (1 << j);
  if (a > 0 && b > 0) return s;
  if (a == 0 && b == 0) return s;
  return s ^ (1 << i) ^ (1 << j);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int s = Read();
  int t = Read();
  vector<int> p(k);
  vector<int> f(1 << k, n + 1), g(1 << k, -1);
  f[s] = 0;
  g[t] = 0;
  for (int i = 0; i < k; ++i) p[i] = i;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    swap(p[a], p[b]);
    s = Update(s, p[a], p[b]);
    t = Update(t, p[a], p[b]);
    f[s] = min(f[s], i + 1);
    g[t] = max(g[t], i + 1);
  }
  int count = 0, a = 0, b = 0;
  for (int i = (1 << k) - 1; i >= 0; --i) {
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) {
        f[i ^ (1 << j)] = min(f[i ^ (1 << j)], f[i]);
        g[i ^ (1 << j)] = max(g[i ^ (1 << j)], g[i]);
      }
      if (g[i] - f[i] >= m && __builtin_popcount(i) > count) {
        count = __builtin_popcount(i);
        a = f[i] + 1;
        b = g[i];
      }
    }
  }
  s = __builtin_popcount(s);
  t = __builtin_popcount(t);
  cout << k - (s - count) - (t - count) << endl;
  cout << a << " " << b << endl;
  return 0;
}
