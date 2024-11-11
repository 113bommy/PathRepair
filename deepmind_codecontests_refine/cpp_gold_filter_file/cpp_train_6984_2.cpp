#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int main() {
  long long int n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  bool vis[n + 1][m + 1];
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      cin >> a[i][j];
      vis[i][j] = false;
    }
  }
  std::vector<long long int> v;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (a[i][j] == '*') {
        long long int s = 101;
        long long int r = i;
        while (a[r][j] == '*' && r > 0) {
          r--;
        }
        s = min(s, i - r - 1);
        long long int c = j;
        while (a[i][c] == '*' && c > 0) {
          c--;
        }
        s = min(s, j - c - 1);
        r = i;
        while (a[r][j] == '*' && r <= n) {
          r++;
        }
        s = min(s, r - i - 1);
        c = j;
        while (a[i][c] == '*' && c <= m) {
          c++;
        }
        s = min(s, c - j - 1);
        if (s != 101 && s != 0) {
          for (long long int k = 0; k <= s; k++) {
            vis[i][j + k] = true;
            vis[i][j - k] = true;
            vis[i - k][j] = true;
            vis[i + k][j] = true;
          }
          v.push_back(i);
          v.push_back(j);
          v.push_back(s);
        }
      }
    }
  }
  long long int f = 0;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      if (a[i][j] == '*' && vis[i][j] == false) f = 1;
    }
  }
  if (f == 1)
    cout << -1;
  else {
    cout << v.size() / 3 << endl;
    for (long long int i = 0; i < v.size(); i += 3) {
      cout << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
    }
  }
}
