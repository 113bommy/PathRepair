#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 29);
int n, m, q;
double lim;
int ans;
vector<pair<int, int> > shift;
char mp[30][30];
map<char, vector<pair<int, int> > > ch;
map<char, bool> appear;
map<char, int> can;
double calc_dis(pair<int, int> a, pair<int, int> b) {
  return sqrt(double(abs(a.first - b.first) * abs(a.first - b.first)) +
              double(abs(a.second - b.second) * abs(a.second - b.second)));
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> lim;
  for (int i = 0; i < n; ++i) {
    cin >> mp[i];
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == 'S') {
        shift.push_back({i, j});
      } else {
        ch[mp[i][j]].push_back({i, j});
        appear[mp[i][j]] = 1;
        appear[mp[i][j] - 'a' + 'A'] = 1;
      }
    }
  }
  string s;
  cin >> q >> s;
  for (int i = 0; i < q; ++i) {
    char c = s[i];
    if (!appear[c]) {
      cout << "-1\n";
      return 0;
    }
    if (shift.empty() && isupper(c)) {
      cout << "-1\n";
      return 0;
    }
    if (isupper(c)) {
      if (can.count(c)) {
        if (can[c] == -1) {
          ans++;
        }
        continue;
      }
      can[c] = -1;
      for (__typeof(ch[c - 'A' + 'a'].begin()) itr = ch[c - 'A' + 'a'].begin();
           itr != ch[c - 'A' + 'a'].end(); itr++) {
        for (__typeof(shift.begin()) it = shift.begin(); it != shift.end();
             it++) {
          if (calc_dis(*itr, *it) <= lim) {
            can[c] = 1;
            break;
          }
        }
        if (can[c] == 1) {
          break;
        }
      }
      if (can[c] == -1) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
