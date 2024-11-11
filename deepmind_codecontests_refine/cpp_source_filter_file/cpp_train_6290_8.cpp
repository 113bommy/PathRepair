#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
template <typename T>
inline T sqr(T n) {
  return (n * n);
}
bool cmp(const string& s, int l, int r, int len) {
  if (len - r + 1 != r) return (len - r + 1 < r);
  for (int i = 0; l + i < r && r + i <= len; i++) {
    if (s[l + i] > s[r + i])
      return true;
    else if (s[l + i] < s[r + i])
      return false;
  }
  return false;
}
int main() {
  string s;
  cin >> s;
  int ans = 0;
  int pos = s.size() - 1;
  while (pos >= 0) {
    int npos = pos;
    ans++;
    while (s[npos] == '0') npos--;
    if (!cmp(s, 0, npos, pos)) break;
    pos = npos - 1;
  }
  cout << ans;
  return 0;
}
