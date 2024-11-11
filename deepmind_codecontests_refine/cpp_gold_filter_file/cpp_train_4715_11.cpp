#include <bits/stdc++.h>
using namespace std;
int gi() {
  char cc = getchar();
  int cn = 0, flus = 1;
  while (cc < '0' || cc > '9') {
    if (cc == '-') flus = -flus;
    cc = getchar();
  }
  while (cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0', cc = getchar();
  return cn * flus;
}
const int N = 500 + 5;
bitset<N * N + 50> f[N];
vector<int> A, B;
int n, m;
void solve(vector<int> a, vector<int> &S, vector<int> &T) {
  int sum = 0;
  for (register int i = 1; i <= n; ++i)
    f[i] = (f[i - 1] | (f[i - 1] << a[i])), sum += a[i];
  if (!f[n][sum / 2] || (sum & 1)) return;
  int t = sum / 2;
  for (register int i = n; i >= 1; --i) {
    if (t >= a[i] && f[i - 1][t - a[i]])
      S.push_back(a[i]), t -= a[i];
    else
      T.push_back(a[i]);
  }
}
signed main() {
  int T = gi();
  f[0][0] = 1;
  while (T--) {
    n = gi(), A.resize(n + 1);
    for (register int i = (1); i <= (n); ++i) A[i] = gi();
    m = gi(), B.resize(m + 1);
    for (register int i = (1); i <= (m); ++i) B[i] = gi();
    if (n != m) {
      puts("No");
      continue;
    }
    vector<int> L, R, U, D;
    solve(A, L, R), solve(B, U, D);
    if (L.empty() || R.empty() || U.empty() || D.empty()) {
      puts("No");
      continue;
    }
    if (L.size() < R.size()) swap(L, R);
    if (U.size() < D.size()) swap(U, D);
    sort(L.begin(), L.end(), greater<int>()), sort(D.begin(), D.end());
    sort(R.begin(), R.end(), greater<int>()), sort(U.begin(), U.end());
    vector<int> dx, dy;
    for (int x : R) dx.push_back(x);
    for (int x : L) dx.push_back(-x);
    for (int y : U) dy.push_back(y);
    for (int y : D) dy.push_back(-y);
    int nx = 0, ny = 0;
    puts("Yes");
    for (register int i = 0; i < n + m; ++i) {
      printf("%d %d\n", nx, ny);
      ((i ^ 1) & 1) ? nx += dx[i / 2] : ny += dy[i / 2];
    }
  }
  return 0;
}
