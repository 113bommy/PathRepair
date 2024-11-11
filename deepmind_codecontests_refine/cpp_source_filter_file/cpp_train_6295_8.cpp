#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int p[maxn], q[maxn], fp[maxn], fq[maxn], f[maxn];
struct BIT {
  long long C[maxn], sz;
  void init(int n) {
    sz = n;
    memset(C, 0, sizeof C);
  }
  inline int lowbit(int x) { return x & (-x); }
  void update(int x, int d) {
    while (x <= sz) {
      C[x] += d;
      x += lowbit(x);
    }
  }
  int sum(int x) {
    int ret = 0;
    while (x > 0) {
      ret += C[x];
      x -= lowbit(x);
    }
    return ret;
  }
  int binary(int k) {
    int l = 0, r = sz + 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (sum(m) >= k)
        r = m - 1;
      else
        l = m + 1;
    }
    return l - 1;
  }
};
BIT T;
int main() {
  int n;
  cin >> n;
  T.init(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    p[i]++;
    fp[i] = p[i] - T.sum(p[i]) - 1;
    T.update(p[i], 1);
  }
  T.init(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", q + i);
    q[i]++;
    fq[i] = q[i] - T.sum(q[i]) - 1;
    T.update(q[i], 1);
  }
  for (int i = 1, j = n - 1; i <= n; i++, j--) {
    if (fp[j] + fq[j] >= i) f[j - 1]++;
    f[j] = (f[j] + fp[j] + fq[j]) % i;
  }
  T.init(n);
  for (int i = 1; i <= n; i++) T.update(i, 1);
  for (int i = 0; i < n; i++) {
    int pos = T.binary(f[i] + 1);
    T.update(pos + 1, -1);
    printf("%d ", pos);
  }
  puts("");
}
