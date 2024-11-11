#include <bits/stdc++.h>
#pragma GCC target("popcnt,sse4.2")
using namespace std;
const int mod = 998244353;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
inline int power(int a, int b) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a);
    a = mult(a, a);
    b >>= 1;
  }
  return out;
}
int n, m;
long long a[200010];
class linear_base {
 public:
  long long dat[60];
  int id[60];
  vector<int> pos;
  int insert(long long x) {
    for (int i = m - 1; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (!dat[i]) {
          dat[i] = x;
          pos.push_back(i);
          return 1;
        }
        x ^= dat[i];
      }
    }
    return 0;
  }
  long long ts[60], S[60];
  void regulate() {
    for (int i = m - 1; i >= 0; i--) {
      for (int j = i - 1; j >= 0; j--) {
        if (dat[j] && ((dat[i] >> j) & 1)) dat[i] ^= dat[j];
      }
    }
    int idcnt = 0;
    for (int i = 0; i < m; i++)
      if (!dat[i]) id[i] = idcnt++;
    for (int i = m - 1; i >= 0; i--) {
      if (dat[i])
        for (int j = i - 1; j >= 0; j--)
          if (!dat[j] && ((dat[i] >> j) & 1)) S[i] |= (1ll << id[j]);
    }
    for (int i = 0; i < m; i++) {
      if (!dat[i]) {
        for (int j = 0; j < pos.size(); j++)
          if ((S[pos[j]] >> id[i]) & 1) ts[id[i]] |= (1ll << j);
      }
    }
  }
} L;
int K, b[200010], cnt[60], C[60][60];
void dfs(int np, long long S) {
  if (np == K) {
    cnt[__builtin_popcountll(S)]++;
    return;
  }
  dfs(np + 1, S);
  dfs(np + 1, S ^ L.dat[L.pos[np]]);
}
int cc[60];
void dfs2(int np, long long S, int curcnt) {
  if (np == m - K) {
    cc[curcnt + __builtin_popcountll(S)]++;
    return;
  }
  dfs2(np + 1, S ^ L.ts[np], curcnt + 1);
  dfs2(np + 1, S, curcnt);
}
int main() {
  scanf("%d%d", &n, &m);
  K = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) K += (b[i] = L.insert(a[i]));
  if (K <= 27) {
    dfs(0, 0);
    for (int i = 0; i <= m; i++) printf("%d ", mult(cnt[i], power(2, n - K)));
  } else {
    L.regulate();
    C[0][0] = 1;
    for (int i = 1; i < 60; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    }
    dfs2(0, 0, 0);
    for (int T = 0; T <= m; T++) {
      int cur = 0;
      for (int pcnt = 0; pcnt <= m; pcnt++) {
        for (int i = 0; i <= min(T, pcnt); i++) {
          int tmp = mult(mult(C[pcnt][i], C[m - pcnt][T - i]), cc[pcnt]);
          if (!(i & 1))
            cur = add(cur, tmp);
          else
            cur = dec(cur, tmp);
        }
      }
      cur = mult(mult(cur, power(2, K)), power(power(2, m), mod - 2));
      printf("%d ", mult(cur, power(2, n - K)));
    }
  }
  return 0;
}
