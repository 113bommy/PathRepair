#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
int fac[300005], inv[300005];
void init() {
  fac[0] = inv[0] = inv[1] = 1;
  for (int i = (int)(2); i <= (int)(300005 - 1); i++)
    inv[i] = 1ll * inv[mo % i] * (mo - mo / i) % mo;
  for (int i = (int)(1); i <= (int)(300005 - 1); i++) {
    fac[i] = 1ll * fac[i - 1] * i % mo;
    inv[i] = 1ll * inv[i - 1] * inv[i] % mo;
  }
}
int power(int x, int y) {
  int s = 1;
  for (; y;) {
    if (y & 1) s = 1ll * s * x % mo;
    if (y /= 2) x = 1ll * x * x % mo;
  }
  return s;
}
const int N = 100005;
int freq[N], cnt[N];
void add(int x) {
  cnt[freq[x]]--;
  cnt[++freq[x]]++;
}
void del(int x) {
  cnt[freq[x]]--;
  cnt[--freq[x]]++;
}
vector<int> heavy;
int n, m, Q;
int e[N], ans[N];
struct que {
  int l, r, k, id;
} q[N];
const int blk = 200;
bool cmpk(que a, que b) {
  return pair<int, int>(a.k, a.l - a.r) < pair<int, int>(b.k, b.l - b.r);
}
bool cmpmo(que a, que b) {
  return pair<int, int>(a.l / blk, a.r) < pair<int, int>(b.l / blk, b.r);
}
int main() {
  init();
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d", &e[i]);
    cnt[e[i]]++;
  }
  for (int i = (int)(1); i <= (int)(m); i++)
    if (cnt[i] >= blk) heavy.push_back(i);
  for (int i = (int)(1); i <= (int)(Q); i++) {
    scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k);
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1, cmpk);
  for (int r = 1; r <= Q;) {
    int l = r, kk = q[l].k, res = 1, las = n, v = 1;
    for (; r <= Q && kk == q[r].k; r++)
      ;
    for (int i = (int)(1); i <= (int)(m); i++)
      res = 1ll * res * fac[kk + cnt[i]] % mo;
    for (int i = (int)(l); i <= (int)(r - 1); i++) {
      int len = q[i].r - q[i].l + 1;
      for (; las > len; v = 1ll * (1ll * m * kk + n - (--las)) % mo * v % mo)
        ;
      ans[q[i].id] = 1ll * res * v % mo;
    }
  }
  sort(q + 1, q + Q + 1, cmpmo);
  int l = 1, r = 0;
  memset(cnt, 0, sizeof(cnt));
  ;
  cnt[0] = m;
  for (int i = (int)(1); i <= (int)(n); i++) add(e[i]);
  for (int i = (int)(1); i <= (int)(Q); i++) {
    for (; q[i].l < l; del(e[--l]))
      ;
    for (; q[i].l > l; add(e[l++]))
      ;
    for (; q[i].r < r; add(e[r--]))
      ;
    for (; q[i].r > r; del(e[++r]))
      ;
    int res = 1;
    for (int j = (int)(0); j <= (int)(blk - 1); j++)
      if (cnt[j]) res = 1ll * res * power(inv[q[i].k + j], cnt[j]) % mo;
    for (int j : heavy)
      if (freq[j] >= blk) res = 1ll * res * inv[q[i].k + freq[j]] % mo;
    ans[q[i].id] = 1ll * ans[q[i].id] * res % mo;
  }
  for (int i = (int)(1); i <= (int)(Q); i++) printf("%d\n", ans[i]);
}
