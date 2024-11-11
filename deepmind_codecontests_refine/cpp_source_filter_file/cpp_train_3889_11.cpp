#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e16;
const long long ninf = LLONG_MIN;
const double eps = 1e-12;
const long long N = 1000005;
const long long LOGN = 19;
const double PI = 3.14159265358979323846;
long long n, m;
long long c[1005][1005];
long long row[1005], col[1005];
long long solve(long long i, long long j) {
  if (i < j) return (j - i) * 4 - 2;
  return (i - j) * 4 + 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long ansx = inf, ansy = inf, px, py;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) row[i] += c[i][j];
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) col[i] += c[j][i];
  for (int i = 0; i < n; i++) {
    long long curr = 0;
    for (int j = 1; j <= n; j++) {
      curr += row[j] * solve(i, j) * solve(i, j);
    }
    if (curr < ansx) {
      ansx = curr;
      px = i;
    }
  }
  for (int i = 0; i < m; i++) {
    long long curr = 0;
    for (int j = 1; j <= m; j++) {
      curr += col[j] * solve(i, j) * solve(i, j);
    }
    if (curr < ansy) {
      ansy = curr;
      py = i;
    }
  }
  cout << ansx + ansy << "\n";
  cout << px << " " << py << "\n";
  return 0;
}
