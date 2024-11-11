#include <bits/stdc++.h>
using namespace std;
vector<int> V[1000005];
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v1, v0,
    w, x, y, pre, z, mx, mxi, x2, y2;
long long L[100005], U[100005], R[100005], D[100005], YN[100005][5],
    S[100005][5], T[100005][5];
int main() {
  cin >> d >> n >> m;
  for (i = 1; i <= d; i++) {
    cin >> x >> y >> x2 >> y2;
    if (x != x2) YN[i][1] = 1;
    if (y != y2) YN[i][2] = 1;
    L[min(x, x2)]++;
    R[max(x, x2)]++;
    U[min(y, y2)]++;
    D[max(y, y2)]++;
    S[i][1] = max(x, x2);
    S[i][2] = min(x, x2);
    S[i][3] = max(y, y2);
    S[i][4] = min(y, y2);
  }
  for (i = 1; i <= n; i++) L[i] = L[i - 1] + L[i];
  for (i = n; i > 0; i--) R[i] = R[i + 1] + R[i];
  for (i = 1; i <= m; i++) U[i] = U[i - 1] + U[i];
  for (i = m; i > 0; i--) D[i] = D[i + 1] + D[i];
  cin >> l >> r >> t >> b;
  for (i = 1; i <= d; i++) {
    a = L[S[i][1] - 1] - YN[i][1];
    if (a != l) continue;
    a = R[S[i][2] + 1] - YN[i][1];
    if (a != r) continue;
    a = U[S[i][3] - 1] - YN[i][2];
    if (a != t) continue;
    a = D[S[i][4] + 1] - YN[i][2];
    if (a != b) continue;
    cout << i;
    return 0;
  }
  cout << -1;
  return 0;
}
