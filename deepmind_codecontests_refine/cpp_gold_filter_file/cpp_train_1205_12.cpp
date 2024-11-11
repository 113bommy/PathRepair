#include <bits/stdc++.h>
using namespace std;
long long n, m;
char c[102][102];
vector<pair<long long, long long> > solve() {
  vector<pair<long long, long long> > an;
  for (int i = 1; i <= n; i += (1 + (1 ^ (n & 1)))) {
    for (int j = 1; j <= m; j += (1 + (n & 1))) {
      if (c[i][j] == 'U' && (n % 2 == 0)) continue;
      if (c[i][j] == 'L' && (n & 1)) continue;
      long long g = 1 ^ (n & 1);
      long long x = i, y = j;
      vector<pair<long long, long long> > v;
      while (true) {
        v.push_back(make_pair(x, y));
        g ^= 1;
        if (g == 0)
          if (c[x + 1][y] == 'L')
            break;
          else {
            x++;
            continue;
          }
        else if (c[x][y + 1] == 'U')
          break;
        else {
          y++;
          continue;
        }
      }
      reverse(v.begin(), v.end());
      for (int l = 0; l < v.size(); l++) {
        an.push_back(v[l]);
        long long x = v[l].first, y = v[l].second;
        if (c[x][y] == 'L') {
          c[x][y] = 'U';
          c[x][y + 1] = 'U';
          c[x + 1][y] = 'D';
          c[x + 1][y + 1] = 'D';
        } else {
          c[x][y] = 'L';
          c[x + 1][y] = 'L';
          c[x][y + 1] = 'R';
          c[x + 1][y + 1] = 'R';
        }
      }
    }
  }
  return an;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  vector<pair<long long, long long> > a = solve();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  vector<pair<long long, long long> > b = solve();
  reverse(b.begin(), b.end());
  for (int i = 0; i < b.size(); i++) a.push_back(b[i]);
  cout << a.size() << '\n';
  for (int i = 0; i < a.size(); i++)
    cout << a[i].first << " " << a[i].second << '\n';
  return 0;
}
