#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, a[N], val[N], b[N];
struct BIT {
  int c[16777999];
  void modify(int p, int v) {
    ++p;
    while (p <= 16777216) c[p] += v, p += p & -p;
  }
  int query(int p) {
    ++p;
    int ret = 0;
    while (p) ret += c[p], p -= p & -p;
    return ret;
  }
  int query(int l, int r) {
    if (l > r) return 0;
    return query(r) - query(l - 1);
  }
} tr[2];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = gi();
  int ans = 0;
  for (int t = 0; t <= 24; t++) {
    int tmp = (1 << t);
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      val[i] = a[i] & (tmp - 1);
      b[i] = a[i] >> t & 1;
      cnt += tr[b[i]].query(tmp - val[i], tmp - 1) +
             tr[b[i] ^ 1].query(0, tmp - val[i] - 1);
      tr[b[i]].modify(val[i], 1);
    }
    for (int i = 1; i <= n; i++) tr[b[i]].modify(val[i], -1);
    if (cnt & 1) ans |= 1 << t;
  }
  cout << ans;
  return 0;
}
