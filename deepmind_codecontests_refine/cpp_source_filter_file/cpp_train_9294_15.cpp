#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  x = x % 998244353;
  if (x == 1) return 1;
  if (y == 0) return 1;
  if (y == 1) return x;
  long long temp = power(x, y >> 1);
  if (y & 1) {
    return ((((temp * temp) % 998244353) * x) % 998244353);
  } else
    return ((temp * temp) % 998244353);
}
void factorial(long long n, vector<long long> &fact) {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i <= n; i++)
    fact[i] = (fact[i - 1] * (i % 998244353)) % 998244353;
  return;
}
long long inv(long long n) { return power(n, 998244353 - 2); }
long long ncr(long long n, long long r, vector<long long> &fact,
              vector<long long> &invfact) {
  if (r > n || r < 0 || n < 0) return 0;
  return ((((fact[n] * invfact[n - r]) % 998244353) * invfact[r]) % 998244353);
}
void find_primes(long long n, vector<long long> &primes) {
  bool isprime[n + 1];
  for (long long i = 0; i <= n; i++) isprime[i] = 1;
  isprime[0] = 0;
  isprime[1] = 0;
  for (long long i = 2; i <= n; i++) {
    if (isprime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        isprime[j] = 0;
      }
    }
  }
  for (long long i = 0; i <= n; i++) {
    if (isprime[i]) {
      primes.push_back(i);
    }
  }
  return;
}
void find_fact1(long long n, vector<long long> &primes,
                vector<unordered_map<long long, long long> > &primfact) {
  vector<long long> cur(n + 1);
  for (long long i = 0; i <= n; i++) {
    cur[i] = i;
  }
  for (auto x : primes) {
    for (long long i = x; i <= n; i += x) {
      long long cnt = 0;
      while (cur[i] % x == 0) {
        cur[i] /= x;
        cnt++;
      }
      primfact[i][x] = cnt;
    }
  }
  return;
}
void find_fact2(long long n, vector<long long> &primes, vector<long long> &sp) {
  for (long long i = 0; i <= n; i++) {
    sp[i] = i;
  }
  for (auto x : primes) {
    for (long long i = x * 2; i <= n; i += x) {
      sp[i] = min(sp[i], x);
    }
  }
  return;
}
void bfs(long long u, vector<vector<long long> > &adj,
         vector<long long> &dist) {
  long long n = adj.size() - 1;
  vector<bool> vis(n + 1, 0);
  vis[u] = 1;
  dist[u] = 0;
  queue<long long> q;
  q.push(u);
  long long level = 1;
  while (!q.empty()) {
    long long k = q.size();
    for (long long i = 0; i < k; i++) {
      long long x = q.front();
      q.pop();
      for (auto y : adj[x]) {
        if (!vis[y]) {
          vis[y] = 1;
          dist[y] = level;
          q.push(y);
        }
      }
    }
    level++;
  }
  return;
}
void kmp(string &s, vector<long long> &lps) {
  long long n = s.size();
  lps.resize(n);
  lps[0] = -1;
  for (long long i = 1; i < n; i++) {
    long long j = lps[i - 1];
    while (s[j + 1] != s[i]) {
      if (j == -1) break;
      j = lps[j];
    }
    if (j != -1 || s[0] == s[i])
      lps[i] = j + 1;
    else
      lps[i] = -1;
  }
}
vector<long long> seg;
void update(long long i, long long tl, long long tr, long long j, long long x) {
  if (tl == tr) {
    seg[i] = x;
    return;
  }
  long long tm = (tl + tr) >> 1;
  long long c = i << 1;
  if (j <= tm)
    update(c + 1, tl, tm, j, x);
  else
    update(c + 2, tm + 1, tr, j, x);
  seg[i] = min(seg[c + 1], seg[c + 2]);
  return;
}
long long query(long long i, long long tl, long long tr, long long rl,
                long long rr) {
  if (rl > rr || tl > rr || tr < rl) {
    return 9223372036854775807;
  }
  long long c = i << 1;
  long long tm = (tl + tr) >> 1;
  if (tl >= rl && tr <= rr) {
    return seg[i];
  }
  return min(query(c + 1, tl, tm, rl, min(rr, tm)),
             query(c + 2, tm + 1, tr, max(tm + 1, rl), rr));
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  seg.resize(4 * (n + 1), -1);
  vector<bool> b(n + 2, 0);
  vector<long long> last(n + 1, -1);
  for (long long i = 0; i < n; i++) {
    if (v[i] != 1) {
      long long temp = query(0, 1, n, 1, v[i] - 1);
      if (temp > last[v[i]]) b[v[i]] = 1;
    }
    last[v[i]] = i;
    update(0, 1, n, v[i], i);
  }
  for (long long i = 2; i <= n + 1; i++) {
    if (query(0, 1, n, 1, i - 1) > last[i]) {
      b[i] = 1;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (v[i] != 1) {
      b[1] = 1;
      break;
    }
  }
  for (long long i = 1; i <= n + 1; i++) {
    if (!b[i]) {
      cout << i << "\n";
      return;
    }
  }
  cout << (n + 2) << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) solve();
}
