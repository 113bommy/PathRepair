#include <bits/stdc++.h>
using namespace std;
const long long MOD = (1e9) + 7;
long long liantong;
long long n, m, k;
struct Node {
  long long u, v, x;
} a[500000 + 10];
long long fa[500000 + 10];
long long c[500000 + 10];
set<long long> s;
bool cmp(Node a, Node b) { return a.x < b.x; }
long long find(long long x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void add(long long u, long long v) {
  s.insert(u), s.insert(v);
  if (find(u) != find(v)) fa[find(u)] = find(v), liantong--;
}
long long pow1(long long x, long long y) {
  return y ? (y & 1 ? x * pow1(x, y - 1) % MOD : pow1(x * x % MOD, y / 2)) : 1;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d", &c[i]);
    fa[i] = i;
  }
  for (long long i = 1; i <= m; i++)
    scanf("%I64d%I64d", &a[i].u, &a[i].v), a[i].x = c[a[i].u] ^ c[a[i].v];
  sort(a + 1, a + 1 + m, cmp);
  long long j = 0;
  long long cnt = 0;
  long long ans = 0;
  for (long long i = 1; i <= m;) {
    j = i;
    liantong = n;
    for (auto x : s) fa[x] = x;
    s.clear();
    while (j <= m && a[i].x == a[j].x) {
      add(a[j].u, a[j].v);
      j++;
    }
    i = j;
    ans += pow(2, liantong);
    ans %= MOD;
    cnt++;
  }
  printf("%I64d\n", (ans + (pow1(2, k) - cnt + MOD) * pow1(2, n) % MOD) % MOD);
  return 0;
}
