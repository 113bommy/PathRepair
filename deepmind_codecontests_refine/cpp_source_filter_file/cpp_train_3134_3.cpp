#include <bits/stdc++.h>
using namespace std;
const int N = 194600;
const int MAX = 5032110;
int n, q;
vector<int> pr[N];
int prv[MAX][8], f[N][15];
vector<int> primes(int a) {
  vector<int> ret;
  for (int i = 2; i * i <= a; ++i)
    if (a % i == 0) {
      while (a % (i * i) == 0) a /= (i * i);
      if (a % i == 0) ret.push_back(i);
    }
  if (a > 1) ret.push_back(a);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    pr[i] = primes(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (i > 1)
      for (int j = 0; j < 15; ++j) f[i][j] = f[i - 1][j];
    int sz = pr[i].size();
    for (int u = 0; u < (1 << sz); ++u) {
      int prd = 1;
      for (int v = 0; v < sz; ++v)
        if (u & (1 << v)) {
          prd *= pr[i][v];
        }
      int d = sz - __builtin_popcount(u);
      for (int dd = 0; dd <= 7; ++dd) {
        f[i][d + dd] = max(f[i][d + dd], prv[prd][dd]);
      }
      prv[prd][d] = i;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 15; ++i)
      if (f[r][i] >= l) {
        cout << i << '\n';
        break;
      }
  }
}
