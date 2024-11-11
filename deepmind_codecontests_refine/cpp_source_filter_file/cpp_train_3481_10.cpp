#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = 2147483647;
const long long LINF = 9223372036854775807;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string a, b, c, d;
bool ok(string s) {
  if (s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[2] > '8') return 0;
  if (c == s) return 0;
  if (s != a) {
    if (s[0] == a[0])
      if (c[0] != a[0] || (c[1] > a[1] && c[1] > s[1]) ||
          (c[1] < a[1] && c[1] < s[1]))
        return 0;
    if (s[1] == a[1])
      if (c[1] != a[1] || (c[0] > a[0] && c[0] > s[0]) ||
          (c[0] < a[0] && c[0] < s[0]))
        return 0;
  }
  if (s != b) {
    if (s[0] == b[0])
      if (c[0] != b[0] || (c[1] > b[1] && c[1] > s[1]) ||
          (c[1] < b[1] && c[1] < s[1]))
        return 0;
    if (s[1] == b[1])
      if (c[1] != b[1] || (c[0] > b[0] && c[0] > s[0]) ||
          (c[0] < b[0] && c[0] < s[0]))
        return 0;
  }
  for (int(i) = 0; i < (3); i++)
    for (int(j) = 0; j < (3); j++) {
      string t;
      t += c[0] + i - 1;
      t += c[1] + j - 1;
      if (s == t) return 0;
    }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c >> d;
  for (int(i) = 0; i < (3); i++)
    for (int(j) = 0; j < (3); j++) {
      string t;
      t += d[0] + i - 1;
      t += d[1] + j - 1;
      if (ok(t)) {
        cout << "OTHER";
        return 0;
      }
    }
  cout << "CHECKMATE";
  return 0;
}
