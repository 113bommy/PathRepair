#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch == '-' && (f = 0) || (ch = getchar());
  while (ch <= '9' && ch >= '0')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return f ? x : -x;
}
long long p[1020], a[1020], b[1020], s[1020][1020], k, V;
long long f1, f2, f3, a1, a2, a3, mn;
long long calc(long long a, long long b, long long c) {
  return a * b + c * b + a * c;
}
void dfs2(int f) {
  if (!f) {
    f3 = V / f1 / f2;
    if (calc(f1, f2, f3) <= mn) {
      mn = calc(f1, f2, f3);
      a1 = f1, a2 = f2, a3 = f3;
    }
    return;
  }
  long long fks = f2;
  for (int i = b[f]; ~i; i--) {
    f2 = fks * s[f][i];
    if (1. * f2 * f2 * f1 < V + 1) dfs2(f - 1);
  }
  f2 = fks;
}
void dfs(int f) {
  if (!f) {
    if (f1 * sqrt(V / f1) * 2 + V / f1 > mn + 1) return;
    return dfs2(k);
  }
  long long fks = f1;
  for (int i = a[f]; ~i; i--) {
    b[f] = a[f] - i;
    f1 = fks * s[f][i];
    if (1. * f1 * f1 * f1 < V + 1) dfs(f - 1);
  }
  f1 = fks;
}
int main(int argc, char const *argv[]) {
  int fuck;
  for (cin >> fuck; fuck; fuck--) {
    cin >> k;
    V = 1;
    for (int i = 1; i <= k; i++) {
      cin >> p[i] >> a[i];
      s[i][0] = 1;
      for (int j = 1; j <= a[i]; j++) s[i][j] = s[i][j - 1] * p[i];
      V *= s[i][a[i]];
    }
    f1 = f2 = f3 = 1;
    mn = 1ll << 62;
    dfs(k);
    cout << (mn << 1) << " " << a1 << " " << a2 << " " << a3 << endl;
  }
  return 0;
}
