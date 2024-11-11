#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int SZ = 1e5 + 10;
void initialize() {}
vector<pair<int, int>> dlt = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
map<pair<int, int>, pair<char, char>> mp{{{-1, 0}, {'^', 'V'}},
                                         {{1, 0}, {'V', '^'}},
                                         {{0, 1}, {'>', '<'}},
                                         {{0, -1}, {'<', '>'}}};
void test_case() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  vector<pair<int, int>> q;
  for (auto &s : arr) cin >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        q.push_back({i, j});
      }
    }
  }
  while (q.size()) {
    int x = q.back().first, y = q.back().second, nx, ny;
    q.pop_back();
    if (arr[x][y] != '.') continue;
    pair<int, int> pr = {-1, -1};
    int cnt = 0;
    for (pair<int, int> p : dlt) {
      nx = x + p.first;
      ny = y + p.second;
      if (0 <= nx and 0 <= ny and nx < n and ny < m and arr[nx][ny] == '.') {
        cnt += 1;
        pr = p;
      }
    }
    if (cnt == 1) {
      arr[x + pr.first][y + pr.second] = mp[pr].first;
      arr[x][y] = mp[pr].second;
      for (pair<int, int> p : dlt) {
        nx = x + p.first;
        ny = y + p.second;
        if (0 <= nx and 0 <= ny and nx < n and ny < m and arr[nx][ny] == '.') {
          q.push_back({nx, ny});
        }
      }
      x += pr.first;
      y += pr.second;
      for (pair<int, int> p : dlt) {
        nx = x + p.first;
        ny = y + p.second;
        if (0 <= nx and 0 <= ny and nx < n and ny < m and arr[nx][ny] == '.') {
          q.push_back({nx, ny});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        cout << "Not unique\n";
        return;
      }
    }
  }
  for (auto s : arr) cout << s << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(0));
  initialize();
  int t;
  t = 1;
  while (t--) {
    test_case();
  }
}
