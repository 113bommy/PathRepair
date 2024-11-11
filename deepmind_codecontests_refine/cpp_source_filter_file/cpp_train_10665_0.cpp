#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long double EPS = 1e-9;
int n, k;
const int N = 100000 + 50;
string s[N];
bool read() {
  cin >> n >> k;
  for (int i = 0; i < int(n); ++i) cin >> s[i];
  return false;
}
int to[N][26];
int first = 1;
void add(int v, string &s) {
  for (int i = 0; i < int(s.size()); ++i) {
    if (to[v][s[i] - 'a'] == -1) {
      to[v][s[i] - 'a'] = first;
      v = first++;
    } else {
      v = to[v][s[i] - 'a'];
    }
  }
}
void init() {
  for (int i = 0; i < int(N); ++i)
    for (int j = 0; j < int(26); ++j) to[i][j] = -1;
}
bool canwin[N];
bool canlose[N];
bool win(int v) {
  for (int i = 0; i < int(26); ++i)
    if (to[v][i] != -1) {
      if (!win(to[v][i])) return canwin[v] = true;
    }
  return canwin[v] = false;
}
bool lose(int v) {
  int cnt = 0;
  for (int i = 0; i < int(26); ++i)
    if (to[v][i] != -1) {
      cnt++;
      if (!lose(to[v][i])) canlose[v] = true;
    }
  return canlose[v] = cnt == 0;
}
string ans[2] = {"First", "Second"};
void solve() {
  init();
  for (int i = 0; i < int(n); ++i) add(0, s[i]);
  win(0);
  lose(0);
  if (canlose[0] && canwin[0]) {
    cout << ans[0] << endl;
    return;
  }
  if (canwin[0]) {
    if (k & 1) {
      cout << ans[0] << endl;
    } else {
      cout << ans[1] << endl;
    }
  } else {
    cout << ans[1] << endl;
  }
}
int main() {
  read();
  solve();
  return 0;
}
