#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int N = 1e5 + 4;
char s[N];
inline void Read(int *a, int n) {
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = (s[i] == 'R');
}
int n, m, Q, ans = N, L[N], R[N], U[N], D[N], f0, f1, u0, u1;
inline void solve() {
  f0 = f1 = 0;
  for (int i = 1; i <= m; i++) {
    f0 += U[i];
    f1 += !U[i];
  }
  for (int i = 1; i <= n; i++) {
    u0 = min(f0, f1 + m) + L[i] + R[i];
    u1 = min(f1, f0 + m) + (!L[i]) + (!R[i]);
    f0 = u0;
    f1 = u1;
  }
  for (int i = 1; i <= m; i++) {
    f0 += D[i];
    f1 += !D[i];
  }
  ans = min(ans, min(f0, f1));
}
int main() {
  n = read();
  m = read();
  Q = read();
  Read(L, n);
  Read(R, n);
  Read(U, m);
  Read(D, m);
  solve();
  swap(n, m);
  swap(L, U);
  swap(R, D);
  solve();
  cout << ans << "\n";
  return (0 - 0);
}
