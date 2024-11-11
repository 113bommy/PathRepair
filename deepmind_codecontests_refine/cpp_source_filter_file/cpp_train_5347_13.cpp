#include <bits/stdc++.h>
using namespace std;
long long C[101][101];
long long Cdeg[101][101][2];
long long state[100][10001];
bool found[100][10001];
long long n, m, k;
long long be(long long sk, long long deg) {
  if (sk == 0) {
    if (deg == 0)
      return 1;
    else
      return 0;
  }
  long long ats = 1;
  while (deg > 0) {
    if (deg % 2 == 1) ats = (ats * sk) % 1000000007;
    sk = (sk * sk) % 1000000007;
    deg >>= 1;
  }
  return ats;
}
long long find(long long r, long long kiek) {
  long long ats = 0;
  if (r == 0) {
    if (kiek > n)
      return 0;
    else
      return Cdeg[n][kiek][1 <= m % n] % 1000000007;
  }
  if (found[r][kiek]) return state[r][kiek];
  for (int i = 0; i <= min(n, kiek); i++)
    ats =
        (ats + find(r - 1, kiek - i) * Cdeg[n][i][i + 1 <= m % n]) % 1000000007;
  found[r][kiek] = true;
  state[r][kiek] = ats;
  return ats;
}
int main(void) {
  cin >> n >> m >> k;
  for (int i = 0; i <= 100; i++) {
    C[0][i] = 0;
    C[i][0] = 1;
    Cdeg[i][0][0] = be(C[i][0], m / n);
    Cdeg[i][0][1] = be(C[i][0], m / n + 1);
    Cdeg[0][i][0] = be(C[0][i], m / n);
    Cdeg[0][i][1] = be(C[0][i], m / n + 1);
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
      Cdeg[i][j][0] = be(C[i][j], m / n);
      Cdeg[i][j][1] = be(C[i][j], m / n + 1);
    }
  }
  cout << find(n - 1, k) << endl;
}
