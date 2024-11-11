#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e18 + 7;
string s0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string s1a = "What are you doing while sending \"",
       s1b = "\"? Are you busy? Will you send \"", s1c = "\"?";
long long q, u, v, f[100005];
char tinh(long long a, long long b) {
  if (b >= f[a]) return '.';
  if (a == 0) return s0[b];
  if (b < s1a.size()) return s1a[b];
  b -= s1a.size();
  if (b < f[a - 1]) return tinh(a - 1, b);
  b -= f[a - 1];
  if (b < s1b.size()) return s1b[b];
  b -= s1b.size();
  if (b < f[a - 1]) return tinh(a - 1, b);
  b -= f[a - 1];
  if (b < s1c.size()) return s1c[b];
  return '.';
}
signed main() {
  f[0] = s0.size();
  for (long long i = 1; i <= 55; i++)
    f[i] = s1b.size() + s1a.size() + s1c.size() + f[i - 1] * 2;
  for (long long i = 56; i <= 100000; i++) f[i] = mod;
  cin >> q;
  string ans = "";
  while (q--) {
    cin >> u >> v;
    ans = ans + tinh(u, v - 1);
  }
  cout << ans;
}
