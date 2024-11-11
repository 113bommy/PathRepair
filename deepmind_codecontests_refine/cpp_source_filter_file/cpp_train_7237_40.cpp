#include <bits/stdc++.h>
using namespace std;
long long a, b, m, n, x, k, c, y, z, i, j, l, r, u, cnt, ans, sum, maxx,
    v[2555][2555], d;
long long na, ma, nb, mb;
long long br[1456789], ar[1456789], mn[1456789], mx[1456789], used[1456789];
char h[1234][1234], p[55][55], g[123][123];
string s[1456789], t, ress;
vector<long long> vec, as;
map<pair<long long, long long>, long long> mmap;
set<long long> ss;
bool ok, oka[1456789];
char ch;
map<pair<int, int>, int> mpp;
long long bpow(long long v, long long u, long long mod) {
  if (!u) return 1;
  long long res = bpow(v, u / 2, mod);
  res = (res * 1ll * res) % mod;
  if (u & 1) res = (res * 1ll * v) % mod;
  return res;
}
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (!a) return b;
  return gcd(b % a, a);
}
void dii() {
  cin >> n >> k;
  if (n % 2)
    cout << (k - 1) / 2 + 1;
  else
    cout << (n - k) / 2 + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  while (q--) dii();
  return 0;
}
