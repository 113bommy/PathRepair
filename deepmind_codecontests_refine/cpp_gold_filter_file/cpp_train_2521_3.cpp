#include <bits/stdc++.h>
using namespace std;
const int LIMIT = 100;
const double ESP = 10e-9;
const int INF = 1000000000;
long long P[2005][2005];
long long mod = 1000000007ll;
int main(int argc, const char *argv[]) {
  int n, m, k;
  for (int i = 0; i <= 1000; i++) {
    P[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      P[i][j] = (P[i - 1][j - 1] + P[i - 1][j]) % mod;
    }
  }
  cin >> n >> m >> k;
  cout << (P[n - 1][2 * k] * P[m - 1][2 * k]) % mod << endl;
  return 0;
}
