#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PI = pair<LL, vector<int>>;
using PLI = pair<LL, int>;
double F[55][55][55];
bool D[55][55][55];
int main() {
  int n;
  vector<LL> A(55);
  vector<int> B(55);
  vector<int> P(55);
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%lld", &A[i]);
  for (int i = (1); i <= (n); ++i) scanf("%d", &B[i]);
  iota(P.begin(), P.end(), 0);
  sort(P.begin() + 1, P.begin() + 1 + n,
       [&](int i, int j) { return A[i] < A[j]; });
  double l = 0.0, r = 1e9;
  for (int run = (1); run <= (100); ++run) {
    double m = (l + r) / 2;
    vector<double> C(55);
    for (int i = (1); i <= (n); ++i) C[i] = A[i] - B[i] * m;
    memset(D, 0, sizeof D);
    function<double(int, int, int)> dfs = [&](int p, int big, int same) {
      double ans = 1e10;
      if (p == 0) return 0.0;
      int idx = P[p];
      if (A[idx] != A[P[p + 1]]) big += same, same = 0;
      if (D[p][big][same]) return F[p][big][same];
      if (big) {
        ans = min(ans, dfs(p - 1, big - 1, same));
      }
      ans = min(ans, dfs(p - 1, big, same + 1) + C[idx]);
      D[p][big][same] = true;
      return F[p][big][same] = ans;
    };
    double ans = dfs(n, 0, 0);
    if (ans <= 0)
      r = m;
    else
      l = m;
  }
  cout << int(round(l * 1000)) << endl;
  return 0;
}
