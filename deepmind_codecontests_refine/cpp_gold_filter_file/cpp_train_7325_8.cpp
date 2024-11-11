#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long md = 1e9 + 7;
int bit[maxn];
long long l[maxn];
vector<int> dv;
int occ[maxn];
long long modexp(long long a, long long ex) {
  long long ans = 1;
  while (ex > 0) {
    if ((ex & 1) == 1) ans = (ans * a) % md;
    a = (a * a) % md;
    ex >>= 1;
  }
  return ans;
}
int qry(int x) {
  int ans = 0;
  while (x > 0) {
    ans += bit[x];
    x -= x & (-x);
  }
  return ans;
}
void upd(int x, int v) {
  while (x < maxn) {
    bit[x] += v;
    x += x & (-x);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  fill(occ, occ + maxn, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    occ[x]++;
  }
  int lft = n;
  long long ans = 0;
  for (int v = 1; v < maxn; v++) {
    dv.clear();
    for (int p = 1; p * p <= v; p++) {
      if (v % p != 0) continue;
      dv.push_back(p);
      if (v / p != p) dv.push_back(v / p);
    }
    sort(dv.begin(), dv.end());
    int cur = 0;
    long long c = 1, d = 1;
    for (int j = dv.size() - 1; j >= 0; j--) {
      int y = dv[j];
      int q = qry(y);
      c = (c * modexp(j + 1, q - cur)) % md;
      cur = q;
    }
    lft -= occ[v - 1];
    upd(1, -lft);
    upd(v, lft);
    upd(1, lft);
    upd(v + 1, -lft);
    cur = 0;
    for (int j = dv.size() - 1; j >= 0; j--) {
      int y = dv[j];
      int q = qry(y);
      d = (d * modexp(j + 1, q - cur)) % md;
      cur = q;
    }
    ans += d - c;
  }
  if (ans < 0) {
    ans = (-ans) % md;
    ans = (md - ans) % md;
  } else
    ans %= md;
  printf("%lld", (ans + 1) % md);
  printf("\n");
}
