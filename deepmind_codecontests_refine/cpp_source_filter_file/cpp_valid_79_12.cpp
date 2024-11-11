#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const double pi = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int limit = 5e5;
int read() {
  int s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
void print(long long x, char c = '\n') {
  write(x);
  putchar(c);
}
long long mod = 998244353;
const int N = 5e5 + 5;
long long n, m, _;
int i, j, k;
map<int, int> mp;
int have2, have5;
string s;
pair<int, int> go() {
  int ans = 0, bit = 1;
  if (mp[1]) ans = 1;
  if (mp[4]) ans = 4;
  if (mp[6]) ans = 6;
  if (mp[8]) ans = 8;
  if (mp[9]) ans = 9;
  if (ans) return {bit, ans};
  if (mp[2] >= 2) bit = 2, ans = 22;
  if (mp[3] >= 2) bit = 2, ans = 33;
  if (mp[5] >= 2) bit = 2, ans = 55;
  if (mp[7] >= 2) bit = 2, ans = 77;
  if (have2) {
    bit = 2, ans = (s[0] - '0') * 10 + 2;
  }
  if (have5) {
    bit = 2, ans = (s[0] - '0') * 10 + 5;
  }
  if (bit == 2) return {bit, ans};
  if (mp[2] && mp[7]) {
    bit = 2, ans = 27;
    return {bit, ans};
  }
  if (s == "573") {
    return {3, 573};
  }
  if (s == "537") {
    return {3, 537};
  }
  if (s == "57") {
    return {2, 57};
  }
  return {0, 0};
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  while (cin >> T)
    while (T--) {
      cin >> n;
      cin >> s;
      mp.clear();
      have2 = 0, have5 = 0;
      for (int i = 0; i < n; i++) {
        mp[s[i] - '0']++;
        if (s[i] == '2') have2 = i;
        if (s[i] == '5') have5 = i;
      }
      pair<int, int> ans = go();
      printf("%d\n", (ans.first));
      printf("%d\n", (ans.second));
    }
  return 0;
}
