#include <bits/stdc++.h>
using namespace std;
template <typename U, typename V>
void Min(U &a, const V &b) {
  if (a > b) a = b;
}
template <typename U, typename V>
void Max(U &a, const V &b) {
  if (a < b) a = b;
}
template <typename U, typename V>
void add(U &a, const V &b) {
  a = (a + b) % 1000000007;
}
template <typename U>
U gcd(U a, U b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a >= b)
    return gcd(a % b, b);
  else
    return gcd(a, b % a);
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % 1000000007;
    a = 1LL * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int pow(int a, int b, int c) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % c;
    a = 1LL * a * a % c;
    b >>= 1;
  }
  return ans;
}
char s[300005], t[300005];
vector<int> g[300005];
int q[300005], to[300005];
pair<int, int> ans;
int res;
char l = '(', r = ')';
void dfs(int u, int d = 0) {
  if (d > 1) return;
  for (auto &v : g[u]) {
    dfs(v, d + 1);
  }
  if (d == 1) {
    for (auto &v : g[u]) {
      int w = int(g[0].size()) - 1 + 2 + int(g[v].size());
      if (res < w) {
        res = w;
        ans = {v, to[v]};
      }
    }
  }
  if (d == 0) {
    for (auto &v : g[u]) {
      int w = 1 + int(g[v].size());
      if (res < w) {
        res = w;
        ans = {v, to[v]};
      }
    }
  }
}
int main() {
  int T, i, j, k, m, n, ca = 0, K;
  scanf("%d%s", &n, s);
  if (n & 1) {
    puts("0\n1 1");
    return 0;
  }
  m = 0;
  for (int i = 0; i < n; i++) m += s[i] == '(';
  if (m != n / 2) {
    puts("0\n1 1");
    return 0;
  }
  int rt = 0, w = 0, mi = 0;
  for (int i = 0; i < n; i++) {
    w += (s[i] == '(' ? 1 : -1);
    if (w < mi) {
      rt = i + 1;
      w = mi;
    }
  }
  for (int i = 0; i < n; i++) t[i] = s[(i + rt) % n];
  t[n] = 0;
  if (t[0] != l) swap(l, r);
  m = 0;
  q[m++] = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == l)
      q[m++] = i + 1;
    else {
      k = q[--m];
      to[k] = i;
      g[q[m - 1]].push_back(k);
    }
  }
  ans = {1, 0};
  res = int(g[0].size());
  dfs(0);
  ans.first = (ans.first - 1 + rt) % n;
  ans.second = (ans.second + rt) % n;
  printf("%d\n%d %d\n", res, ans.first + 1, ans.second + 1);
}
