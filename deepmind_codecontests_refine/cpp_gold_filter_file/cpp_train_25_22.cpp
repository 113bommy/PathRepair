#include <bits/stdc++.h>
using namespace std;
void input() {
  freopen("input.txt", "r", stdin);
  freopen("dekho.txt", "w", stdout);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char a[n][n];
    for (long long i = (0); i < (n); i++)
      for (long long j = (0); j < (n); j++) cin >> a[i][j];
    if (a[0][1] == a[1][0]) {
      if ((a[n - 1][n - 2] == a[n - 2][n - 1]) && a[n - 1][n - 2] == a[0][1]) {
        cout << 2 << endl;
        cout << n << " " << n - 1 << endl << n - 1 << " " << n << endl;
      } else {
        if (a[0][1] == a[n - 1][n - 2])
          cout << 1 << endl << n << " " << n - 1 << endl;
        else if (a[0][1] == a[n - 2][n - 1])
          cout << 1 << endl << n - 1 << " " << n << endl;
        else
          cout << 0 << endl;
      }
    } else if (a[n - 1][n - 2] == a[n - 2][n - 1]) {
      if (a[0][1] == a[n - 1][n - 2])
        cout << 1 << endl << 1 << " " << 2 << endl;
      else if (a[1][0] == a[n - 2][n - 1])
        cout << 1 << endl << 2 << " " << 1 << endl;
      else
        cout << 0 << endl;
    } else {
      if (a[0][1] == a[n - 1][n - 2]) {
        cout << 2 << endl;
        cout << 2 << " " << 1 << endl << n << " " << n - 1 << endl;
      } else if (a[0][1] == a[n - 2][n - 1]) {
        cout << 2 << endl;
        cout << 2 << " " << 1 << endl << n - 1 << " " << n << endl;
      } else if (a[1][0] == a[n - 1][n - 2]) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl << n << " " << n - 1 << endl;
      } else if (a[1][0] == a[n - 2][n - 1]) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl << n - 1 << " " << n << endl;
      }
    }
  }
  return 0;
}
