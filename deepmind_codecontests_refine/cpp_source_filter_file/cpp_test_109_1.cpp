#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long double dist(long double x, long double arayikhalatyan, long double x2,
                 long double y2) {
  return sqrt((x - x2) * (x - x2) +
              (arayikhalatyan - y2) * (arayikhalatyan - y2));
}
long long int S(long long int a) { return (a * (a + 1LL)) / 2; }
mt19937 rnd(363542);
char vow[] = {'a', 'e', 'i', 'o', 'u'};
int dx[] = {0, -1, 0, 1, -1, -1, 1, 1, 0};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};
const int N = 1e5 + 20;
const long long int mod = 998244353;
const long double pi = acos(-1);
const int T = 200;
long long int bp(long long int a, long long int b = mod - 2LL) {
  long long int ret = 1;
  while (b) {
    if (b & 1) ret *= a, ret %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ret;
}
ostream& operator<<(ostream& c, pair<int, int> a) {
  c << a.first << " " << a.second;
  return c;
}
template <class T>
void maxi(T& a, T b) {
  a = max(a, b);
}
template <class T>
void mini(T& a, T b) {
  a = min(a, b);
}
int n;
int r0, r1, l0, l1;
string s[N];
long long int f[N], ans;
long long int c(int n, int k) {
  long long int ret = f[n] * bp(f[k]);
  ret %= mod;
  ret *= bp(f[n - k]);
  ret %= mod;
  return ret;
}
long long int ss() {
  int sm = 0, a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i][0] == s[i][1] && s[i][0] == '?')
      sm++;
    else if (s[i][0] == s[i][1])
      return 0;
    if (s[i][0] == 'W' || s[i][1] == 'B')
      a++;
    else if (s[i][0] == 'B' || s[i][1] == 'W')
      b++;
  }
  long long int ret = bp(2, sm);
  if (a == 0) ret--;
  if (b == 0) ret--;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  f[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * 1LL * i;
    f[i] %= mod;
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i][0] == 'W')
      l0++;
    else if (s[i][0] == 'B')
      l1++;
    if (s[i][1] == 'W')
      r0++;
    else if (s[i][0] == 'B')
      r1++;
  }
  for (int i = 0; i <= n - l0 - l1; i++) {
    int l00 = l0 + i;
    int l11 = n - l00;
    int r00 = l11;
    int r11 = l00;
    if (r00 < r0 || r11 < r1) continue;
    ans += (c(n - l0 - l1, i) * c(n - r0 - r1, r11 - r1)) % mod;
    ans %= mod;
  }
  ans -= ss();
  ans = (ans + mod) % mod;
  cout << ans << endl;
  return 0;
}
