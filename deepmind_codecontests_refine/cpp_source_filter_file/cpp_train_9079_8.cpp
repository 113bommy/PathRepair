#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
void exkmp(char *a, char *b, int M, int N, int *Next, int *ret) {
  int i, j, k;
  for (j = 0; j + 1 < M && a[j] == a[j + 1]; ++j)
    ;
  Next[1] = j;
  k = 1;
  for (i = 2; i < M; ++i) {
    int Len = k + Next[k], L = Next[i - k];
    if (L < Len - i) {
      Next[i] = L;
    } else {
      for (j = max(0, Len - i); i + j < M && a[j] == a[i + j]; ++j)
        ;
      Next[i] = j;
      k = i;
    }
  }
  for (j = 0; j < N && j < M && a[j] == b[j]; ++j)
    ;
  ret[0] = j;
  k = 0;
  for (i = 1; i < N; ++i) {
    int Len = k + ret[k], L = Next[i - k];
    if (L < Len - i) {
      ret[i] = L;
    } else {
      for (j = max(0, Len - i); j < M && i + j < N && a[j] == b[i + j]; ++j)
        ;
      ret[i] = j;
      k = i;
    }
  }
}
char a[maxn], b[maxn], s[maxn * 2];
int n, m, fa[maxn], fb[maxn], nxt[maxn * 2];
struct FenwickTree {
  long long C[maxn];
  void add(int x, int v) {
    for (int i = x + 1; i <= n + 1; i += ((i) & (-i))) C[i] += v;
  }
  long long query(int x) {
    if (x <= 0 || x > n) return 0ll;
    long long ret = 0ll;
    for (int i = x + 1; i; i -= ((i) & (-i))) ret += C[i];
    return ret;
  }
  long long query(int r, int l) {
    if (r < l) return 0;
    return query(r) - query(l);
  }
} fwt1, fwt2;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s%s", a, b, s);
  char t = s[m - 1];
  s[m - 1] = 0;
  exkmp(s, a, m - 1, n, nxt, fa);
  s[m - 1] = t;
  reverse(s, s + m);
  s[m - 1] = 0;
  reverse(b, b + n);
  exkmp(s, b, m - 1, n, nxt, fb);
  reverse(fb, fb + n);
  for (int i = n; i; --i) {
    fa[i] = fa[i - 1];
    fb[i] = fb[i - 1];
  }
  long long ans = 0ll;
  for (int l1 = 1, r2 = 0, v; l1 <= n; ++l1) {
    while (r2 + 1 <= min(n, l1 + m - 2)) {
      ++r2;
      fwt1.add(fb[r2], fb[r2]);
      fwt2.add(fb[r2], 1);
    }
    v = m - fa[l1] - 1;
    ans += 1ll * -v * fwt2.query(n, v - 1);
    ans += fwt1.query(n, v - 1);
    fwt1.add(fb[l1], -fb[l1]);
    fwt2.add(fb[l1], -1);
  }
  cout << ans << endl;
  return 0;
}
