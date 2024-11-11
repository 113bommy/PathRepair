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
const int maxn = 1e5 + 17;
char s[maxn];
int n, mx[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> mp;
void check(char *s) {
  for (int i = 0; i < 10; i++)
    if ((i == 2 || i == 5) ^ (s[i] == '-')) return;
  string y(s + 6, s + 10);
  if (y != "2013" && y != "2014" && y != "2015") return;
  int m = (s[3] - '0') * 10 + (s[4] - '0');
  if (m < 1 || 12 < m) return;
  int d = (s[0] - '0') * 10 + (s[1] - '0');
  if (d < 1 || d > mx[m]) return;
  mp[string(s, s + 10)]++;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  scanf("%s", s), n = strlen(s);
  for (int i = 0; i <= n - 10; i++) check(s + i);
  int mx = 0;
  for (auto &x : mp) smax(mx, x.second);
  for (auto &x : mp)
    if (x.second == mx) cout << x.first << '\n';
  return 0;
}
