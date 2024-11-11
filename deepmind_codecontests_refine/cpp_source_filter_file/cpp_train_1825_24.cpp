#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 998244353;
struct node {
  int l;
  char c;
} a[N], b[N];
int n, m;
int nxt[N];
void get(node *a, int &n) {
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (m == 0 || a[m - 1].c != a[i].c)
      a[m++] = a[i];
    else
      a[m - 1].l += a[i].l;
  }
  n = m;
}
void get_nxt() {
  nxt[1] = 0;
  int i;
  int j;
  for (i = 2, j = 0; i < m - 1; i++) {
    while (j && !(b[j + 1].l == b[i].l && b[j + 1].c == b[i].c)) j = nxt[j];
    if ((b[j + 1].l == b[i].l && b[j + 1].c == b[i].c)) j++;
    nxt[i] = j;
  }
}
long long solve() {
  get_nxt();
  int i, j;
  long long ans = 0;
  for (i = 0, j = 0; i < n; i++) {
    while (j && !((b[j + 1].l == a[i].l && b[j + 1].c == a[i].c))) j = nxt[j];
    if (b[j + 1].l == a[i].l && b[j + 1].c == a[i].c) j++;
    if (j == m - 2) {
      if (a[i + 1].c == b[m - 1].c && a[i + 1].l >= b[m - 1].l &&
          a[i - m + 2].c == b[0].c && a[i - m + 2].l >= b[0].l)
        ans++;
      j = nxt[j];
    }
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%lld-%c", &a[i].l, &a[i].c);
  for (int i = 0; i < m; ++i) scanf("%lld-%c", &b[i].l, &b[i].c);
  get(a, n);
  get(b, m);
  if (m == 1) {
    long long ans = 0;
    int i;
    for (i = 0; i < n; i++) {
      if (a[i].c == b[0].c && a[i].l >= b[0].l) {
        ans += a[i].l - b[0].l + 1;
      }
    }
    cout << ans << endl;
  } else if (m == 2) {
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i].c == b[0].c && a[i].l >= b[0].l && a[i + 1].c == b[1].c &&
          a[i + 1].l >= b[1].l)
        ans++;
    }
    cout << ans << endl;
  } else {
    cout << solve() << endl;
  }
  return 0;
}
