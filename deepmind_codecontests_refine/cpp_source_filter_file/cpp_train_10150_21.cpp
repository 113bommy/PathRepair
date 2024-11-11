#include <bits/stdc++.h>
using namespace std;
char x[500][501];
int d[2][501][501], n, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < (n); i++) cin >> x[i];
  for (int ei = 0; ei < (n); ei++)
    for (int si = n; si--;)
      for (int sj = m; sj--;) {
        auto &c = d[ei][si][sj] = 0, ej = n + m - 2 - si - sj - ei;
        if (si <= ei && sj <= ej && x[si][sj] == x[ei][ej] &&
            !(c = abs(si - ei) + abs(sj - ej) <= 1))
          for (int i = 0; i < (2); i++)
            for (int j = 0; j < (2); j++)
              c = (c + d[ei - !j & 1][si + !i][sj + i]) % ((int)1e9 + 7);
      }
  cout << d[~n & 1][0][0] << '\n';
}
