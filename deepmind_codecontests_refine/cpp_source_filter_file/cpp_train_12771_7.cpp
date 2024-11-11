#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
const int N = 1e5 + 5, MOD = 1e9 + 7, INF = 1e9 + 5;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  char grid[50][50];
  a--, b--, c--, d--;
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      grid[i][j] = 'A';
      if (i & 1 && j & 1 && d) {
        grid[i][j] = 'D';
        d--;
      }
    }
  }
  for (int i = 0; i < 25; i++) {
    for (int j = 25; j < 50; j++) {
      grid[i][j] = 'B';
      if (!(i & 1) && !(j & 1) && c) {
        grid[i][j] = 'C';
        c--;
      }
    }
  }
  for (int i = 25; i < 50; i++) {
    for (int j = 0; j < 25; j++) {
      grid[i][j] = 'C';
      if (i & 1 && j & 1 && b) {
        grid[i][j] = 'B';
        b--;
      }
    }
  }
  for (int i = 25; i < 50; i++) {
    for (int j = 25; j < 50; j++) {
      grid[i][j] = 'D';
      if (!(i & 1) && !(j & 1) && d) {
        grid[i][j] = 'A';
        a--;
      }
    }
  }
  cout << "50 50\n";
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) cout << grid[i][j];
    cout << "\n";
  }
}
