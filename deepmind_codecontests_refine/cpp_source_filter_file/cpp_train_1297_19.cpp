#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL d[1 << 20];
int main() {
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  int m = v[0].size();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) {
        int same = 0;
        for (int k = 0; k < m; k++)
          if (v[i][k] == v[j][k]) same |= 1 << k;
        d[same] |= 1LL << i;
      }
  for (int mask = (1 << m) - 1; mask; mask--) {
    for (int i = 0; i < m; i++)
      if (mask & 1 << i) d[mask ^ 1 << i] |= d[mask];
  }
  long double ans = 0, p = 1;
  for (int cnt = 0; cnt <= m; cnt++) {
    p = p * (cnt + 1) / (m - cnt);
    for (int mask = 0; mask < (1 << m); mask++) {
      if (__builtin_popcount(mask) != cnt) continue;
      for (int i = 0; i < m; i++) {
        if (mask & 1 << i || d[mask] & d[mask | 1 << i] != d[mask | 1 << i])
          continue;
        LL res = d[mask] ^ d[mask | 1 << i];
        int num = __builtin_popcount(res);
        ans += num * p;
      }
    }
  }
  ans /= n;
  printf("%.14f\n", (double)ans);
  return 0;
}
