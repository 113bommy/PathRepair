#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 21;
int n;
int a[MAXN][MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) a[i][j] = 1 + (i + j) % n;
  for (int i = 0; i < n; i++) {
    a[i][n] = a[n][i] = a[i][i];
    a[i][i] = 0;
  }
  n++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
