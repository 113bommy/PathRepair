#include <bits/stdc++.h>
const bool DEBUG = false;
using namespace std;
const long long maxn = 3e5 + 5 + 1;
const long long INF = 4e18;
const long long M = 1e9 + 7;
const int lg = 21;
int n, m, a[60][60], ans;
char c;
pair<int, int> s, e;
vector<char> f;
bool ok(pair<int, int> h) {
  if (h.first < 0 or h.first >= n) {
    return false;
  }
  if (h.second < 0 or h.second >= m) {
    return false;
  }
  if (a[h.first][h.second]) {
    return false;
  }
  return true;
}
bool play(char u, char d, char l, char r) {
  pair<int, int> t = s;
  for (int i = 0; i < f.size(); i++) {
    if (f[i] == u) {
      t.first = t.first - 1;
    }
    if (f[i] == d) {
      t.first = t.first + 1;
    }
    if (f[i] == l) {
      t.second = t.second - 1;
    }
    if (f[i] == r) {
      t.second = t.second + 1;
    }
    if (t == e) {
      return true;
    }
    if (!ok(t)) {
      return false;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == '#') {
        a[i][j] = 1;
      }
      if (c == 'S') {
        s.first = i, s.second = j;
      }
      if (c == 'E') {
        e.first = i, e.second = j;
      }
    }
  }
  while (cin >> c) {
    f.push_back(c);
  }
  if (play('0', '1', '2', '3')) ans++;
  if (play('0', '1', '3', '2')) ans++;
  if (play('0', '2', '1', '3')) ans++;
  if (play('0', '2', '3', '1')) ans++;
  if (play('0', '3', '1', '2')) ans++;
  if (play('0', '3', '2', '1')) ans++;
  if (play('1', '0', '2', '3')) ans++;
  if (play('1', '0', '3', '2')) ans++;
  if (play('1', '2', '0', '3')) ans++;
  if (play('1', '2', '3', '0')) ans++;
  if (play('1', '3', '0', '2')) ans++;
  if (play('1', '3', '2', '0')) ans++;
  if (play('2', '1', '0', '3')) ans++;
  if (play('2', '1', '3', '0')) ans++;
  if (play('2', '0', '1', '3')) ans++;
  if (play('2', '0', '3', '1')) ans++;
  if (play('2', '3', '1', '0')) ans++;
  if (play('2', '3', '0', '1')) ans++;
  if (play('3', '1', '2', '0')) ans++;
  if (play('3', '1', '0', '2')) ans++;
  if (play('3', '2', '1', '0')) ans++;
  if (play('3', '2', '0', '1')) ans++;
  if (play('3', '0', '1', '2')) ans++;
  if (play('3', '0', '2', '1')) ans++;
  cout << ans;
  return 0;
}
