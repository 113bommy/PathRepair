#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
struct Bit {
  long long N;
  vector<long long> dat;
  Bit(long long n) : N(n), dat(n) {}
  long long sum(long long i) {
    long long s = 0;
    while (i > 0) {
      s += dat[i - 1];
      s %= mod;
      i -= i & -i;
    }
    return s;
  }
  void add(long long i, long long x) {
    while (i <= N) {
      dat[i - 1] += x;
      dat[i - 1] %= mod;
      i += i & -i;
    }
  }
};
struct Ruiseki {
  Bit bit0;
  Bit bit1;
  Ruiseki(long long n) : bit0(n), bit1(n) {}
  long long sum(long long l, long long r) {
    l++;
    r++;
    r--;
    return (bit1.sum(r) * r % mod + bit0.sum(r) -
            bit1.sum(l - 1) * (l - 1) % mod - bit0.sum(l - 1)) %
           mod;
  }
  void add(long long l, long long r, long long x) {
    l++;
    r++;
    r--;
    bit1.add(l, x);
    bit1.add(r + 1, -x);
    bit0.add(l, (l - 1) * -x);
    bit0.add(r + 1, r * x);
  }
};
long long N;
long long Q;
vector<long long> G[600300];
vector<long long> vs;
long long begini[600300];
long long endi[600300];
long long depth[600300];
long long k;
void dfs(long long cur, long long par, long long d) {
  vs.push_back(cur);
  begini[cur] = k;
  k++;
  depth[cur] = d;
  for (long long i = 0; i < (G[cur].size()); ++i) {
    long long to = G[cur][i];
    if (to == par) continue;
    dfs(to, cur, d + 1);
    vs.push_back(cur);
    k++;
  }
  endi[cur] = k;
}
signed main() {
  cin >> N;
  for (long long i = 0; i < (N - 1); ++i) {
    long long p;
    cin >> p;
    --p;
    G[i + 1].push_back(p);
    G[p].push_back(i + 1);
  }
  dfs(0, -1, 0);
  Ruiseki rui1(2 * N + 10), rui2(2 * N + 10);
  cin >> Q;
  for (long long i = 0; i < (Q); ++i) {
    long long type;
    scanf("%lld", &type);
    if (type == 1) {
      long long v, x, k;
      scanf("%lld%lld%lld", &v, &x, &k);
      v--;
      rui1.add(begini[v], endi[v], (x + k * depth[v]) % mod);
      rui2.add(begini[v], endi[v], k);
    } else {
      long long v;
      scanf("%lld", &v);
      v--;
      printf("%lld\n", ((rui1.sum(begini[v], begini[v] + 1) -
                         rui2.sum(begini[v], begini[v] + 1) * depth[v] % mod) +
                        mod * 100) %
                           mod);
    }
  }
}
