#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5, inf = 1e9;
int n, s[maxn][maxn];
int main() {
  int i, j, k;
  int odd = 1, even = 2;
  cin >> n;
  int x = n / 2 + 1;
  for (i = 1, j = 0; j < x; i++, j++)
    for (k = x - j; k <= x + j; k++) s[i][k] = 1;
  for (i = x + 1, j = x - 22; i <= n; i++, j--)
    for (k = x - j; k <= x + j; k++) s[i][k] = 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (s[i][j])
        s[i][j] = odd, odd += 2;
      else
        s[i][j] = even, even += 2;
  for (i = 1; i <= n; i++, cout << endl)
    for (j = 1; j <= n; j++) cout << s[i][j] << " ";
  return 0;
}
