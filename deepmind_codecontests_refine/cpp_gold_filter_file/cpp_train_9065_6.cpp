#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long double PI = 3.141592653589793;
vector<pair<pair<int, int>, int>> v;
char s[1000][1000];
int check_size(int a, int b, int n, int m) {
  int p = 0, q = 0, r = 0, s1 = 0;
  for (int i = a + 1; (i < n && s[i][b] == '*'); i++) p++;
  for (int i = a - 1; (i >= 0 && s[i][b] == '*'); i--) q++;
  for (int i = b + 1; (i < m && s[a][i] == '*'); i++) r++;
  for (int i = b - 1; (i >= 0 && s[a][i] == '*'); i--) s1++;
  return (min(min(p, q), min(r, s1)));
}
void check(int a, int b, int n, int m, int min) {
  for (int i = b; i <= b + min; i++) s[a][i] = '.';
  for (int i = b; i >= b - min; i--) s[a][i] = '.';
  for (int i = a; i <= a + min; i++) s[i][b] = '.';
  for (int i = a; i >= a - min; i--) s[i][b] = '.';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> s[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        if ((i - 1 >= 0 && s[i - 1][j] == '*') &&
            (j - 1 >= 0 && s[i][j - 1] == '*') &&
            (i + 1 < n && s[i + 1][j] == '*') &&
            (j + 1 < m && s[i][j + 1] == '*')) {
          v.push_back(make_pair(make_pair(i, j), 1));
        }
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    int r = check_size(v[i].first.first, v[i].first.second, n, m);
    v[i].second = max(r, v[i].second);
  }
  for (int i = 0; i < v.size(); i++) {
    check(v[i].first.first, v[i].first.second, n, m, v[i].second);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') {
        cout << -1;
        return 0;
      }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first.first + 1 << ' ' << v[i].first.second + 1 << ' '
         << v[i].second << '\n';
  cerr << "Time Lapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
  return 0;
}
