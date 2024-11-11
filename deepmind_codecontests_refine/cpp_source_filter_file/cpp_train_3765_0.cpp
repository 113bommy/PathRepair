#include <bits/stdc++.h>
using namespace std;
int a[300300], pre1[300300], pre2[300300];
long long qp(long long a, long long b, long long mod) {
  long long ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
  }
  return ret;
}
long long p1[300300], p2[300300];
int comp[300300][2];
const long long md1 = 998244353, md2 = 19260817;
int st[23][300300];
int highbit(int x) { return 31 - __builtin_clz(x); }
void build(int n) {
  for (int i = 0; i < highbit(n) + 1; i++) {
    for (int j = 1; j <= n - (1 << (i)) + 1; j++) {
      if (i == 0)
        st[i][j] = j;
      else if (a[st[i - 1][j]] >= a[st[i - 1][j + (1 << (i - 1))]])
        st[i][j] = st[i - 1][j];
      else
        st[i][j] = st[i - 1][j + (1 << (i - 1))];
    }
  }
  return;
}
int que(int l, int r) {
  assert(r >= l && r < 300300);
  int t = highbit(r - l + 1);
  if (a[st[t][l]] > a[st[t][r - (1 << t) + 1]])
    return st[t][l];
  else
    return st[t][r - (1 << t) + 1];
}
int lpp[300300], rpp[300300], ans[300300];
long long solve(int l, int r) {
  long long ret = 0;
  if (l > r) return 0;
  int pt = que(l, r);
  if ((pt - l) < (r - pt)) {
    int lpt = l, rpt = l + a[pt] - 1;
    while (lpt <= pt && rpt <= r) {
      if (rpt >= pt &&
          comp[a[pt]][0] == (pre1[rpt] - pre1[lpt - 1] + md1) % md1 &&
          comp[a[pt]][1] == (pre2[rpt] - pre2[lpt - 1] + md2) % md2)
        ret++;
      lpt++;
      rpt++;
    }
  } else {
    int rpt = r, lpt = r - a[pt] + 1;
    while (rpt >= pt && lpt >= l) {
      if (rpt >= pt &&
          comp[a[pt]][0] == (pre1[rpt] - pre1[lpt - 1] + md1) % md1 &&
          comp[a[pt]][1] == (pre2[rpt] - pre2[lpt - 1] + md2) % md2)
        ret++;
      rpt--;
      lpt--;
    }
  }
  return ret + solve(l, pt - 1) + solve(pt + 1, r);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(n);
  p1[0] = p2[0] = 1;
  for (int i = 1; i < 300300; i++) {
    p1[i] = p1[i - 1] * 233 % md1;
    p2[i] = p2[i - 1] * 114514 % md2;
  }
  for (int i = 1; i < 300300; i++) {
    comp[i][0] = comp[i - 1][0] + p1[i];
    comp[i][1] = comp[i - 1][1] + p2[i];
    comp[i][0] = (comp[i][0] < md1) ? comp[i][0] : (comp[i][0] - md1);
    comp[i][1] = (comp[i][1] < md2) ? comp[i][1] : (comp[i][1] - md2);
  }
  for (int i = 1; i <= n; i++) {
    pre1[i] = (pre1[i - 1] + p1[a[i]]) % md1;
    pre2[i] = (pre2[i - 1] + p2[a[i]]) % md2;
  }
  long long ans = solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
