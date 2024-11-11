#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n][n];
  int c = 0;
  for (int i = 0; i < n / 2; i++)
    for (int j = 0; j < n / 2; j++)
      a[i][j] = 4 * c, a[i + n / 2][j] = 4 * c + 1, a[i][j + n / 2] = 4 * c + 2,
      a[i + n / 2][j + n / 2] = 4 * c + 3, c++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
}
