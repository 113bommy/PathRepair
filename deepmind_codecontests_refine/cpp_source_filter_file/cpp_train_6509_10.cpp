#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[200010];
double P[200010], X[200010], F[200010][60];
double EX(int l, int r) {
  return ((P[r] - P[l - 1]) - (double)a[l - 1] * (X[r] - X[l - 1]));
}
void cal(int l, int r, int j, int kmin, int kmax) {
  if (r < l) return;
  int mid = (l + r) / 2, best = kmin;
  for (int p = kmin; p <= min(kmax, mid - 1); p++)
    if (F[p][j - 1] + EX(p + 1, mid) < F[mid][j])
      best = p, F[mid][j] = F[p][j - 1] + EX(p + 1, mid);
  cal(l, mid - 1, j, kmin, best);
  cal(mid + 1, r, j, best, kmax);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), a[i] += a[i - 1];
  for (int i = 1; i <= n; i++)
    P[i] = (double)a[i] / (double)(a[i] - a[i - 1]), X[i] = P[i] / (double)a[i],
    P[i] += P[i - 1], X[i] += X[i - 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++) F[i][j] = 1e9 + 7;
  F[0][0] = 0;
  for (int i = 1; i <= k; i++) cal(1, n, i, 0, n);
  cout << setprecision(5);
  cout << fixed;
  cout << F[n][k];
}
