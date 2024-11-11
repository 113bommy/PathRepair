#include <bits/stdc++.h>
using namespace std;
const long long INF = 10000000000;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long prime(long long p) {
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return false;
  }
  return true;
}
double dist(long long x1, long long y1, long long x2, long long y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
string lower(string a) {
  long long q = a.size();
  for (long long i = 0; i < q; i++) {
    if (a[i] >= 'A' and a[i] <= 'Z') a[i] = char((a[i] - 'A') + 'a');
  }
  return a;
}
long long powmod(long long a, long long b, long long mod) {
  if (a == 1 or b == 0) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2) {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  }
}
vector<long long> nbase(long long n, long long base) {
  long long cur = 0;
  vector<long long> m(32, 0);
  while (n != 0) {
    m[cur] = n % base;
    n /= base;
    cur++;
  }
  long long y = 0;
  for (long long i = 31; i >= 0; i--) {
    if (m[i] != 0) {
      y = i;
      break;
    }
  }
  vector<long long> ans(y + 1);
  for (long long i = 0; i < y + 1; i++) ans[i] = m[i];
  return ans;
}
long long phi(long long b) {
  long long func = b;
  long long c = b;
  for (long long i = 2; i * i <= c; i++) {
    if (b % i == 0) {
      func /= i;
      func *= i - 1;
    }
    while (b % i == 0) b /= i;
  }
  if (b != 1) {
    func /= b;
    func *= b - 1;
  }
  return func;
}
vector<long long> prefix_function(string s) {
  long long n = s.size();
  vector<long long> pi(n);
  for (long long i = 1; i < n; ++i) {
    long long j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
vector<vector<long long>> pal(string s) {
  long long n = s.size();
  vector<vector<long long>> p(2, vector<long long>(n, 0));
  for (long long z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0)
    for (long long i = 0; i < n; i++) {
      if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
      long long L = i - p[z][i], R = i + p[z][i] - !z;
      while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1])
        p[z][i]++, L--, R++;
      if (R > r) l = L, r = R;
    }
  return p;
}
const long long mod = 1000000007;
long long sub(long long a, long long b) { return ((a - b) % mod + mod) % mod; }
long long n, m;
vector<vector<long long>> e;
vector<bool> colors, used;
bool ok = true;
void dfs(long long start, bool color) {
  used[start] = true;
  colors[start] = color;
  long long k = e[start].size();
  for (long long i = 0; i < k; i++) {
    if (used[e[start][i]] and colors[e[start][i]] == colors[start])
      ok = false;
    else if (!used[e[start][i]]) {
      dfs(e[start][i], !colors[start]);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long a = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '-') {
      a = max(0LL, a);
    } else
      a++;
  }
  cout << a;
}
