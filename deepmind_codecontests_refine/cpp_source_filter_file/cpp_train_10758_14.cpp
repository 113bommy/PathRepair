#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 10;
const long long mod = 1e9 + 7;
long long d;
long long len;
string s;
string t;
long long hash_l[maxn];
long long hash_r[maxn];
long long p[maxn];
long long base = 113;
void in();
void solve();
long long get_l(long long x, long long y);
long long get_r(long long x, long long y);
long long check(long long x);
long long dfs(long long x, long long sta);
void out();
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  in();
  solve();
  out();
}
void in() {
  cin >> d >> s;
  s = "." + s;
  for (int i = 0; i < s.size(); i++) t += '.';
}
void solve() {
  len = s.size();
  for (long long i = len; i >= 1; --i) {
    if (s[i] == 'z')
      s[i] = 'a';
    else {
      s[i]++;
      break;
    }
    if (i == 1) {
      cout << "Impossible\n";
      exit(0);
    }
  }
  p[1] = 1;
  for (long long i = 2; i <= len; ++i) p[i] = p[i - 1] * base % mod;
}
long long get_l(long long x, long long y) {
  return (hash_l[x] - hash_l[x - y] * p[y + 1] % mod + mod) % mod;
}
long long get_r(long long x, long long y) {
  return (hash_r[x] - hash_r[x - y] + mod) % mod;
}
long long check(long long x) {
  if (x >= d && get_l(x, d) * p[x - d + 1] % mod == get_r(x, d)) return 1;
  if (x > d && get_l(x, d + 1) * p[x - d] % mod == get_r(x, d + 1)) return 1;
  return 0;
}
long long dfs(long long x, long long sta) {
  if (x > len) return 1;
  char c;
  if (sta)
    c = s[x];
  else
    c = 'a';
  for (char i = c; i <= 'z'; ++i) {
    t[x] = i;
    hash_l[x] = (hash_l[x - 1] * base % mod + (i - 'a' + 1)) % mod;
    hash_r[x] = (hash_r[x - 1] + p[x] * (i - 'a' + 1) % mod) % mod;
    if (check(x)) continue;
    if (dfs(x + 1, sta && t[x] == s[x])) return 1;
  }
  return 0;
}
void out() {
  if (dfs(1, 1))
    cout << t.substr(1, t.size() - 1) << '\n';
  else
    cout << "Impossible\n";
}
