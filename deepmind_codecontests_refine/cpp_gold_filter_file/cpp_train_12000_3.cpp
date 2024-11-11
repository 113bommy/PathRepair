#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1, tmp = 0;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<long long int> > v(n + 1, vector<long long int>(n + 1, 0));
    for (long long int i = 0; i < n + 1; ++i) {
      for (long long int j = 0; j < n + 1; ++j) {
        if (i % 2 == 0)
          v[i][j] = 0;
        else
          v[i][j] = (1LL << (i + j));
      }
    }
    for (long long int i = 0; i < n; ++i) {
      for (long long int j = 0; j < n; ++j) cout << v[i][j] << ' ';
      cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
      long long int tmp;
      cin >> tmp;
      cout << "1 1" << endl;
      int x = 0, y = 0;
      for (long long int i = 1; i <= 2 * n - 2; ++i) {
        long long int hi = 1LL << (x + y + 1);
        if (v[x + 1][y] == (tmp & hi)) {
          x++;
        } else
          y++;
        cout << x + 1 << ' ' << y + 1;
        cout << endl;
      }
    }
  }
  return 0;
}
