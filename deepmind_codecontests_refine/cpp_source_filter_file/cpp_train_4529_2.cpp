#include <bits/stdc++.h>
using namespace std;
long long d[5005][5005], cst[300005];
long long c(int poz, int len) { return cst[poz + len] - cst[poz + 1]; }
int main() {
  int n, k;
  long long x;
  vector<long long> elems;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    elems.push_back(x);
  }
  sort(elems.begin(), elems.end());
  cst[1] = 0;
  for (int i = 2; i <= n; ++i)
    cst[i] = cst[i - 1] + elems[i - 1] - elems[i - 2];
  int gr1 = n / k, gr2 = n / k + 1, n1 = k - n % k, n2 = n % k;
  for (int i = 0; i <= n1; ++i)
    for (int j = 0; j <= n2; ++j) d[i][j] = 1LL << 15;
  d[1][0] = c(0, gr1);
  d[0][1] = c(0, gr2);
  for (int i = 2; i <= n1; ++i) d[i][0] = d[i - 1][0] + c((i - 1) * gr1, gr1);
  for (int i = 2; i <= n2; ++i) d[i][0] = d[i - 1][0] + c((i - 1) * gr2, gr2);
  for (int i = 1; i <= n1; ++i) {
    for (int j = 1; j <= n2; ++j)
      d[i][j] = min(d[i - 1][j] + c((i - 1) * gr1 + j * gr2, gr1),
                    d[i][j - 1] + c(i * gr1 + (j - 1) * gr2, gr2));
  }
  cout << d[n1][n2];
  return 0;
}
