#include <bits/stdc++.h>
using namespace std;
int xx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const double pi = 3.14159265358;
const int INF = 1e9;
map<string, int> m;
void read() {
  int n, i, j, k, mn;
  string s;
  cin >> n;
  while (n--) {
    cin >> k >> s;
    sort(s.begin(), s.end());
    if (m.count(s) == 0)
      m[s] = k;
    else
      m[s] = min(m[s], k);
  }
}
int get(string s, string t) {
  if (!m.count(s) || !m.count(t)) return INF;
  return m[s] + m[t];
}
void solve() {
  int ans = INF;
  if (m.count("A'") && m.count("B") && m.count("C"))
    ans = m["A"] + m["B"] + m["C"];
  if (m.count("ABC")) ans = min(ans, m["ABC"]);
  ans = min(ans, get("A", "BC"));
  ans = min(ans, get("B", "AC"));
  ans = min(ans, get("C", "AB"));
  ans = min(ans, get("AB", "BC"));
  ans = min(ans, get("AC", "BC"));
  ans = min(ans, get("AB", "AC"));
  if (ans == INF) ans = -1;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
