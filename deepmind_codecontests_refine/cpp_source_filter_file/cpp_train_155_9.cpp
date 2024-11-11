#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const int oo = 0x7fffffff;
const int sup = 0x80000000;
template <typename it>
void db(it *begin, it *end) {
  while (begin != end) cout << (*begin++) << " ";
  puts("");
}
template <typename it>
string to_str(it n) {
  string s = "";
  while (n) s += n % 10 + '0', n /= 10;
  reverse(s.begin(), s.end());
  return s;
}
template <typename it>
int o(it a) {
  cout << a << endl;
  return 0;
}
inline long long mul_64(long long x, long long y, long long c) {
  return (x * y - (long long)((long double)x / c * y) * c + c) % c;
}
long long ksm(long long a, long long b, long long c) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % c)
    if (b & 1) ans = ans * a % c;
  return ans;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else
    exgcd(b, a % b, y, x), y -= (a / b) * x;
}
int n, k;
int a, b, c, d;
bool vis[N];
vector<int> g;
int main() {
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  vis[a] = vis[b] = vis[c] = vis[d] = 1;
  if (k == n - 1 || n == 4) return o(-1);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) g.push_back(i);
  cout << a << " " << c << " ";
  for (int v : g) cout << v << " ";
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (int v : g) cout << v << " ";
  cout << b << " " << d << endl;
}
