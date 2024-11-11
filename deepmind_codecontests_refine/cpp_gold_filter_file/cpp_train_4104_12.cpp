#include <bits/stdc++.h>
using namespace std;
const int maxN = 5020;
int n, big[maxN][maxN], small[maxN][maxN], a[maxN], MAX = 5010 * 5010, fi, se,
                                                    ted, inv;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int(i) = (1); (i) < (int)(n + 1); ++(i)) cin >> a[i];
  for (int(i) = (1); (i) < (int)(n + 1); ++(i))
    for (int(j) = (1); (j) < (int)(i); ++(j))
      if (a[i] < a[j]) inv++;
  for (int(i) = (1); (i) < (int)(n + 1); ++(i))
    for (int(j) = (0); (j) < (int)(n); ++(j))
      big[i][j] = big[i - 1][j] + (a[i] > j);
  for (int i = n; i > 0; i--)
    for (int(j) = (0); (j) < (int)(n); ++(j))
      small[i][j] = small[i + 1][j] + (a[i] < j);
  for (int(i) = (1); (i) < (int)(n + 1); ++(i))
    for (int(j) = (i + 1); (j) < (int)(n + 1); ++(j))
      if (a[i] > a[j]) {
        int tot = big[j][a[i]] - big[i][a[i]] + big[i - 1][a[j]] - big[j][a[j]];
        tot += small[j + 1][a[i]] - small[i][a[i]] + small[i][a[j]] -
               small[j][a[j]];
        if (tot < MAX) {
          MAX = tot;
          fi = i;
          se = j;
          ted = 1;
        } else if (tot == MAX)
          ted++;
      }
  cout << inv + MAX + 1 << ' ' << ted << endl;
  return 0;
}
