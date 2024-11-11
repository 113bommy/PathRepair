#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string& fileName, bool local = 0) {
  if (fileName.empty()) return;
  if (local) {
    freopen((fileName + ".in").c_str(), "r", stdin);
    freopen((fileName + ".out").c_str(), "w", stdout);
    return;
  }
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
}
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 61) - 1;
const double EPS = 1e-10, PI = acos(-1);
const int N = 55, D = 21;
int n;
string s[N];
long long poss[1 << D];
double f[1 << D];
int main() {
  srand((int)time(0));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int mask = 0;
      for (int p = 0; p < s[i].length(); p++) {
        if (s[i][p] == s[j][p]) {
          mask |= 1 << p;
        }
      }
      poss[mask] |= 1 << i | 1 << j;
    }
  }
  int len = (int)s[0].length();
  for (int i = (1 << len) - 1; i >= 0; i--) {
    for (int j = 0; j < len; j++) {
      if (~i >> j & 1) continue;
      poss[i ^ (1 << j)] |= poss[i];
    }
  }
  for (int mask = (1 << len) - 1; mask >= 0; mask--) {
    int cnt = 0;
    if (!__builtin_popcountll(poss[mask])) continue;
    for (int i = 0; i < len; i++) {
      if (mask >> i & 1) continue;
      int nmask = mask | 1LL << i;
      f[mask] += f[nmask] * __builtin_popcountll(poss[nmask]) /
                     __builtin_popcountll(poss[mask]) +
                 1;
      ++cnt;
    }
    if (!cnt) continue;
    f[mask] /= cnt;
  }
  printf("%.10lf\n", f[0]);
  return 0;
}
