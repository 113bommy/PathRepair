#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000009;
int n, nr1, nr2, D[1010000];
int d(int n1, int n2) {
  int i, rez = 1;
  for (i = n1 + 1; i <= n1 + n2; ++i) rez = (1LL * rez * i) % MOD;
  D[0] = 1;
  D[1] = 1;
  D[2] = 2;
  for (i = 3; i <= n1; ++i)
    D[i] = (1LL * D[i - 1] + 1LL * D[i - 2] * (i - 1)) % MOD;
  rez = (1LL * rez * D[n1]) % MOD;
  return rez;
}
int main() {
  int i;
  cin >> n;
  for (i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    if (t == 1)
      ++nr1;
    else
      ++nr2;
  }
  cout << d(nr1, nr2);
  return 0;
}
