#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int NN = 1e3 + 1;
const long long MOD = 1e9 + 7;
const long long oo = 1e18 + 7;
void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i <= n - 3; i++)
    for (int j = 1; j <= n - 2; j++)
      if (a[i][j] == '.') {
        int check = true;
        if (a[i + 1][j - 1] == '#') check = false;
        if (a[i + 1][j] == '#') check = false;
        if (a[i + 1][j + 1] == '#') check = false;
        if (a[i + 2][j] == '#') check = false;
        if (check) {
          a[i][j] = '*';
          a[i + 1][j - 1] = '*';
          a[i + 1][j] = '*';
          a[i + 1][j + 1] = '*';
          a[i + 2][j] = '*';
        }
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == '.') {
        cout << "NO";
        return;
      }
  cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  solve();
}
