#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
inline long long in() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long N = 1e6 + 100;
long long offset = 2e5 + 2;
long long tree[N], a[N], b[N], n;
void upd(long long id, long long x) {
  while (id < N) {
    tree[id] += x;
    id += (id & -id);
  }
}
long long get(long long id) {
  long long ans = 0;
  while (id >= 1) {
    ans += tree[id];
    id -= (id & -id);
  }
  return ans;
}
long long g(long long m) {
  for (long long i = 1; i < N; i++) tree[i] = 0;
  for (long long i = 1; i <= n; i++)
    if (a[i] < m)
      b[i] = -1;
    else
      b[i] = 1;
  for (long long i = 1; i <= n; i++) b[i] += b[i - 1];
  for (long long i = 0; i <= n; i++) b[i] += offset;
  long long ct = 0;
  for (long long i = 0; i <= n; i++) {
    ct += get(b[i]);
    upd(b[i] + 1, 1);
  }
  return ct;
}
int32_t main() {
  long long m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) a[i] = in();
  cout << g(m) - g(m + 1) << "\n";
}
