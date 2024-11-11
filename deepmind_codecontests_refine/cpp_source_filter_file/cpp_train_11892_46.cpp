#include <bits/stdc++.h>
using namespace std;
int C[2010][2010], n, m, k;
int main() {
  for (int i = 0; i < 2000; ++i)
    for (int j = 0; j < i + 1; ++j)
      C[i][j] = (j ? (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007 : 1);
  cin >> n >> m >> k;
  cout << ((C[n - 1][2 * k]) % 1000000007 * (C[m - 1][2 * k]) % 1000000007) %
              1000000007
       << endl;
  return 0;
}
