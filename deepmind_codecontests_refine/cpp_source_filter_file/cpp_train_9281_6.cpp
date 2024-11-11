#include <bits/stdc++.h>
#pragma optimize("", off)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const long long int N = 5e5 + 5;
const long long int M = 1e9 + 7;
long long int jt[4 * N];
long long int n;
vector<long long int> ip;
map<long long int, long long int> a1, a2;
void update(long long int l, long long int h, long long int p, long long int q,
            long long int v) {
  if (l == h) {
    jt[p] += v;
    return;
  }
  long long int m = (l + h) >> 1;
  if (m >= q)
    update(l, m, 2 * p + 1, q, v);
  else
    update(m + 1, h, 2 * p + 2, q, v);
  jt[p] = (jt[2 * p + 1] + jt[2 * p + 2]);
  return;
}
long long int query(long long int l, long long int h, long long int p,
                    long long int ql, long long int qh) {
  if (l > qh || h < ql)
    return 0;
  else if (l >= ql && h <= qh)
    return jt[p];
  long long int m = (l + h) >> 1;
  long long int p1 = query(l, m, 2 * p + 1, ql, qh);
  long long int p2 = query(m + 1, h, 2 * p + 2, ql, qh);
  return p1 + p2;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  cin >> n;
  ip.resize(n + 1);
  for (long long int i = 1; i <= n; i++) cin >> ip[i], a1[ip[i]];
  long long int c = 0;
  for (auto &it : a1) {
    it.second = ++c;
    a2[c] = it.first;
  }
  for (long long int i = 1; i <= n; i++) ip[i] = a1[ip[i]];
  memset(jt, 0, sizeof(jt));
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    update(1, n, 0, ip[i], i);
    long long int val = query(1, n, 0, 1, ip[i]);
    val *= a2[ip[i]];
    val %= M;
    val *= (n - i + 1);
    val %= M;
    ans += val;
    ans %= M;
  }
  memset(jt, 0, sizeof(jt));
  for (long long int i = n; i > 0; i--) {
    long long int val = query(1, n, 0, 1, ip[i] - 1);
    val *= a2[ip[i]];
    val %= M;
    val *= i;
    val %= M;
    ans += val;
    ans %= M;
    update(1, n, 0, ip[i], n - i + 1);
  }
  cout << ans;
}
