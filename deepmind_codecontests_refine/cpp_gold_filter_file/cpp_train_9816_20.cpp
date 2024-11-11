#include <bits/stdc++.h>
const int N = 2e5 + 10;
const int mod = 998244353;
const double PI = acos(-1.0);
const double eps = 1e-8;
using namespace std;
inline int read() {
  int num = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w ? -num : num;
}
inline int lowbit(int x) { return x & -x; }
int n, q, t, a[N];
long long pre[N], sumx, cnt[16];
void mynext_permutation() {
  long long temp = sumx;
  int m = upper_bound(cnt, cnt + 16, sumx) - cnt;
  int b[m + 1], c[m + 1], len = m;
  for (int i = 1; i <= m; ++i) c[i] = i;
  long long suf[16];
  suf[m] = 1;
  for (int j = 2; j <= m; ++j) suf[m + 1 - j] = suf[m + 2 - j] * j;
  for (int i = 1; i < m && temp; ++i) {
    int chos = temp / suf[i + 1] + 1;
    temp = temp % suf[i + 1];
    b[i] = c[chos];
    for (int i = chos; i < len; ++i) c[i] = c[i + 1];
    --len;
  }
  for (int i = len, j = m; i >= 1; --i, --j) b[j] = c[i];
  for (int i = n - m, j = 1; i < n; ++i, ++j) a[i] = n - m + b[j];
}
void solve() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) a[i] = i + 1;
  pre[0] = a[0];
  for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << pre[r] - pre[l] + a[l] << endl;
    } else {
      int x;
      cin >> x;
      sumx += x;
      mynext_permutation();
      pre[0] = a[0];
      for (int i = max(1, n - 15); i < n; ++i) pre[i] = pre[i - 1] + a[i];
    }
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cnt[1] = 1;
  for (int i = 2; i <= 15; ++i) cnt[i] = cnt[i - 1] * i;
  solve();
  return 0;
}
