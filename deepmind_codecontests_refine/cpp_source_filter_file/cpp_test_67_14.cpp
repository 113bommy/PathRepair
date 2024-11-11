#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3 + 5;
const double EPS = 1e-9;
vector<vector<long long>> C(mxN, vector<long long>(4, -1));
long long ini(int n, int k) {
  if (n == k || k == 0) return C[n][k] = 1;
  if (C[n][k] != -1) return C[n][k];
  return C[n][k] = ini(n - 1, k - 1) + ini(n - 1, k);
}
int main() {
  int n;
  cin >> n;
  double p;
  cin >> p;
  if (p == 0) {
    cout << "0\n";
    return 0;
  }
  ini(mxN - 1, 3);
  for (int i = 2; i < n; ++i) {
    double tot = C[n][3];
    double ans = (double)(n - i >= 2 ? i * C[n - i][2] : 0) * 0.5 +
                 (n - i >= 3 ? C[n - i][3] : 0);
    if (p <= (tot - ans) / tot + EPS) {
      cout << i << '\n';
      return 0;
    }
  }
}
