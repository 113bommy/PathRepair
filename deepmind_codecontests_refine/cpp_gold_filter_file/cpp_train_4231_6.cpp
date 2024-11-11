#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 100005;
const double PI = 4 * atan(1);
set<char> vowel = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i'};
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
bool issquare(long long w) { return trunc(sqrt(w)) * trunc(sqrt(w)) == w; }
bool isprime(long long u) {
  for (long long i = 2; i <= (int)sqrt(u); i++) {
    if (u % i == 0) return 0;
  }
  return 1;
}
long long mod(long long to_mod, long long modulo = MOD) {
  to_mod %= modulo;
  while (to_mod < 0) to_mod += modulo;
  return to_mod % modulo;
}
long long moduloMultiplication(long long a, long long b, long long mod) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long n, m, k, a, l, r, b, t, ans = 0, res = 0, x, y, z, xmax, xmin;
vector<long long> vv, v;
vector<vector<long long> > troll;
double db;
vector<pair<long long, long long> > vvv;
priority_queue<pair<long long, long long> > pq;
map<long long, vector<long long> > adj;
char c;
map<string, long long> points;
queue<pair<long long, long long> > q;
map<long long, long long> maa;
string ch, ch1, ch2;
stack<long long> ss;
long long ti[200005];
long long tab[200005];
void add(long long v1, long long v2) {
  v1--;
  v2--;
  adj[v1].push_back(v2);
  adj[v2].push_back(v1);
}
int main() {
  ios_base::sync_with_stdio(false);
  memset(ti, -1, sizeof(ti));
  memset(tab, -1, sizeof(tab));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  ti[0] = 0;
  ans = 1;
  for (int i = 1; i <= n; i++) {
    x = v[i - 1];
    if (ti[x] != -1) {
      y = ti[x];
      ti[i] = y;
      ti[x] = -1;
      tab[y] = i;
    } else {
      ti[i] = ans;
      tab[ans] = i;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
