#include <bits/stdc++.h>
using namespace ::std;
const long double PI = acos(-1);
const long long MOD = 1000000000 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long add(long long a, long long b, long long m = MOD) {
  if (a >= m) a %= m;
  if (b >= m) b %= m;
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = a + b;
  if (res >= m or res <= -m) res %= m;
  if (res < 0) res += m;
  return res;
}
long long mul(long long a, long long b, long long m = MOD) {
  if (a >= m) a %= m;
  if (b >= m) b %= m;
  if (a < 0) a += m;
  if (b < 0) b += m;
  long long res = a * b;
  if (res >= m or res <= -m) res %= m;
  if (res < 0) res += m;
  return res;
}
long long pow_mod(long long a, long long b, long long m = MOD) {
  long long res = 1LL;
  a = a % m;
  while (b) {
    if (b & 1) res = mul(res, a, m);
    b >>= 1;
    a = mul(a, a, m);
  }
  return res;
}
long long fastexp(long long a, long long b) {
  long long res = 1LL;
  while (b) {
    if (b & 1) res = res * a;
    b >>= 1;
    a *= a;
  }
  return res;
}
int gcdExtendido(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0;
    *y = 1;
    return b;
  }
  int x1, y1;
  int gcd = gcdExtendido(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
int modInverso(int a, int m) {
  int x, y;
  int g = gcdExtendido(a, m, &x, &y);
  if (g != 1)
    return -1;
  else
    return (x % m + m) % m;
}
const int N = 17000 + 5;
const int K = 100 + 5;
const long long inf = 1e18;
const int E = 26;
int n;
int k;
int h[N];
char s[K];
int nodes = 1;
long long memo[K][N];
map<int, int> trie[N];
int subtree[N];
void insert() {
  int pos = 0;
  for (int i = 0; s[i]; i++) {
    int nxt = s[i] - 'a';
    if (!trie[pos].count(nxt)) {
      trie[pos][nxt] = nodes++;
    }
    pos = trie[pos][nxt];
    h[pos] = i + 1;
  }
  subtree[pos] += 1;
}
void DP(int u) {
  vector<long long> carry(k + 1);
  for (int i = 0; i <= subtree[u]; i++) {
    memo[i][u] = 1LL * h[u] * i * (i - 1) / 2LL;
  }
  for (auto x : trie[u]) {
    int v = x.second;
    DP(v);
    carry.assign(k + 1, 0LL);
    for (int i = 0; i <= min(subtree[u], k); i++) {
      for (int j = 0; j <= subtree[v] and i + j <= k; j++) {
        carry[i + j] =
            max(carry[i + j], memo[i][u] + 1LL * i * j * h[u] + memo[j][v]);
      }
    }
    subtree[u] += subtree[v];
    for (int i = 0; i <= min(subtree[u], k); i++) {
      memo[i][u] = max(memo[i][u], carry[i]);
    }
  }
}
int main() {
  scanf("%d %d", &(n), &(k));
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    insert();
  }
  DP(0);
  printf("%lld\n", memo[k][0]);
  return 0;
}
