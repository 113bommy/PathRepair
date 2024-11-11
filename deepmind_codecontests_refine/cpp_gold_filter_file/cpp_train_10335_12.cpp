#include <bits/stdc++.h>
using namespace ::std;
long long comb[5001][5001];
long long pperm[5001];
long long fact[5001];
int main() {
  ifstream fin("input.txt");
  long long n, m, p;
  cin >> n >> m >> p;
  comb[1][1] = 1;
  for (int i = 2; i <= 5000; i++)
    for (int j = 2; j <= 5000; j++) {
      comb[i][j] = (comb[i - 1][j - 1] + (j - 1) * comb[i - 1][j]) % p;
    }
  pperm[1] = m;
  for (int i = 2; i <= 5000; i++) pperm[i] = (pperm[i - 1] * (m - i + 1)) % p;
  fact[1] = 1;
  for (int i = 2; i <= 5000; i++) fact[i] = (fact[i - 1] * i) % p;
  vector<vector<long long> > garland(2, vector<long long>(5001));
  vector<long long> rows(2);
  cin >> rows[0];
  if (m == 1 and (n > 1 or rows[0] != 1)) {
    cout << 0;
    exit(0);
  }
  int cur = 0;
  for (int i = 1; i <= min(rows[0], m); i++) {
    garland[0][i] = ((comb[rows[0]][i] * pperm[i]) + p) % p;
  }
  long long prevsum;
  for (int i = 1, cur = 1; i < n; i++, cur = cur ^ 1) {
    prevsum = 0;
    cin >> rows[cur];
    for (int k = 1; k <= rows[cur ^ 1]; k++)
      prevsum = (prevsum + garland[cur ^ 1][k]) % p;
    for (long long j = 1; j <= min(rows[cur], m); j++) {
      garland[cur][j] =
          ((prevsum * (comb[rows[cur]][j] * pperm[j] % p)) % p + p) % p;
      if (j <= rows[cur ^ 1])
        garland[cur][j] =
            ((garland[cur][j] -
              garland[cur ^ 1][j] * (comb[rows[cur]][j] * fact[j] % p)) %
                 p +
             p) %
            p;
    }
  }
  long long answ = 0;
  for (int i = 1; i <= rows[(n % 2) ^ 1]; i++) {
    answ = (answ + garland[(n % 2) ^ 1][i]) % p;
  }
  cout << answ;
  cout << "\n";
}
