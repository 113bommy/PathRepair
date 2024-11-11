#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return y < x ? (x = y, 1) : 0;
}
const int maxn = 17;
string s[maxn];
vector<string> ans, cur;
void write(string &s, int x, int y, int px, int py) {
  for (int i = 0; i < s.size(); x += px, y += py, i++) cur[x][y] = s[i];
}
void solve() {
  if (s[0][0] != s[3][0]) return;
  if (s[0].back() != s[4][0]) return;
  if (s[1][0] != s[3].back()) return;
  if (s[1].back() != s[5][0]) return;
  if (s[2][0] != s[4].back()) return;
  if (s[2].back() != s[5].back()) return;
  if (s[1][s[0].size() - 1] != s[4][s[3].size() - 1]) return;
  if (s[0].size() + s[2].size() != s[1].size() + 1) return;
  if (s[3].size() + s[5].size() != s[4].size() + 1) return;
  cur = vector<string>(s[4].size(), string(s[1].size(), '.'));
  write(s[0], 0, 0, 0, 1);
  write(s[1], s[3].size() - 1, 0, 0, 1);
  write(s[2], s[0].size() - 1, s[4].size() - 1, 0, 1);
  write(s[3], 0, 0, 1, 0);
  write(s[4], 0, s[0].size() - 1, 1, 0);
  write(s[5], s[3].size() - 1, s[1].size() - 1, 1, 0);
  if (ans.size() == 0 || ans > cur) ans = cur;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 0; i < 6; i++) cin >> s[i];
  sort(s, s + 6);
  do {
    solve();
  } while (next_permutation(s, s + 6));
  if (ans.size() == 0) ans.push_back("Impossible");
  for (auto x : ans) cout << x << '\n';
  return 0;
}
