#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, L = 47;
long long A[N], PS[N], n, rt, xr;
struct DBST {
  long long D[N * L][2], SZ[N * L], st = 0;
  inline DBST() {
    memset(D, 0, sizeof(D));
    memset(SZ, 0, sizeof(SZ));
  }
  void add(long long a, long long i = L - 1, long long nd = 0) {
    SZ[nd]++;
    if (!(~i)) return;
    long long ind = a >> i & 1LL;
    if (!D[nd][ind]) D[nd][ind] = ++st;
    if (!D[nd][ind ^ 1]) D[nd][ind ^ 1] = ++st;
    add(a, i - 1, D[nd][ind]);
  }
  long long get(long long a, long long rt = 0, long long i = L - 1,
                long long nd = 0) {
    if (!(~i)) return (rt);
    long long ind = 1 - (a >> i & 1LL);
    if (!D[nd][ind]) D[nd][ind] = ++st;
    if (!D[nd][ind ^ 1]) D[nd][ind ^ 1] = ++st;
    if (!SZ[D[nd][ind]])
      return (get(a, rt | (a & (1LL << i)), i - 1, D[nd][ind ^ 1]));
    else
      return (get(a, rt | (a & (1LL << i) ^ (1LL << i)), i - 1, D[nd][ind]));
  }
} f1;
int32_t main() {
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) scanf("%lld", &A[i]);
  for (long long i = n - 1; ~i; i--) PS[i] = PS[i + 1] ^ A[i];
  for (long long i = 0; i < n; i++) rt = max(rt, PS[i]);
  for (long long i = 0; i < n; i++) f1.add(PS[i]);
  for (long long i = 0; i < n; i++) {
    xr ^= A[i];
    rt = max(rt, xr ^ f1.get(xr));
    rt = max(rt, xr);
  }
  printf("%lld", rt);
}
