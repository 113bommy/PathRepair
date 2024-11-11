#include <bits/stdc++.h>
using namespace std;
const int N = 500023;
bool vis[N];
vector<int> adj[N];
void solve() {
  long long int n, m;
  cin >> n >> m;
  map<char, pair<long long int, long long int>> start;
  map<char, pair<long long int, long long int>> end;
  char coor[n + 1][m + 1];
  int flag[200] = {0};
  for (long long int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (long long int j = 1; j <= m; j++) {
      char ch = s[j - 1];
      coor[i][j] = ch;
      if (ch == '.') continue;
      if (flag[ch] == 0) start[ch] = make_pair(i, j);
      flag[ch]++;
      end[ch] = make_pair(i, j);
    }
  }
  char highest = 'A';
  for (char ch = 'z'; ch >= 'a'; ch--) {
    if (flag[ch] != 0) {
      highest = ch;
      break;
    }
  }
  if (highest == 'A') {
    cout << "YES\n";
    cout << 0 << '\n';
    return;
  } else {
    long long int k = highest - 'a' + 1;
    for (char ch = highest; ch >= 'a'; ch--) {
      if (flag[ch] == 0) {
        start[ch] = start[highest];
        end[ch] = end[highest];
        continue;
      }
      long long int count = 0;
      if (start[ch].first == end[ch].first) {
        for (long long int i = start[ch].second; i <= end[ch].second; i++) {
          if (coor[start[ch].first][i] == '.') {
            cout << "NO\n";
            return;
          }
          if (coor[start[ch].first][i] < ch) {
            cout << "NO\n";
            return;
          }
          if (coor[start[ch].first][i] == ch) count++;
        }
        if (flag[ch] != count) {
          cout << "NO\n";
          return;
        }
      } else if (start[ch].second == end[ch].second) {
        for (long long int i = start[ch].first; i <= end[ch].first; i++) {
          if (coor[i][start[ch].second] == '.') {
            cout << "NO\n";
            return;
          }
          if (coor[i][start[ch].second] < ch) {
            cout << "NO\n";
            return;
          }
          if (coor[i][start[ch].second] == ch) count++;
        }
        if (flag[ch] != count) {
          cout << "NO\n";
          return;
        }
      } else {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    cout << k << '\n';
    for (char ch = 'a'; ch <= highest; ch++)
      cout << start[ch].first << ' ' << start[ch].second << ' ' << end[ch].first
           << ' ' << end[ch].second << '\n';
  }
}
int main() {
  int T = 1;
  cin >> T;
  int t = 0;
  while (t++ < T) {
    solve();
  }
}
