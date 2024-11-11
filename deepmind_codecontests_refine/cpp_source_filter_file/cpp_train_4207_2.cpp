#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 9;
int a[MAX][MAX], n;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  if (n == 4) return cout << -1, 0;
  for (int i = 0; i < n; i++) a[i][(i + 1) % n] = 1;
  for (int i = 0; i < n; i++)
    for (int j = i + 2; j < n; j++)
      if ((i + j) % 2 == 1)
        a[j][i] = 1;
      else
        a[i][j] = 1;
  a[0][n - 1] = 0;
  for (int i = 0; i < n; i++, cout << '\n')
    for (int j = 0; j < n; j++) cout << a[i][j];
  return 0;
}
