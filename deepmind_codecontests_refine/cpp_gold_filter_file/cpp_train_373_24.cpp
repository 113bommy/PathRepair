#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
long long n, q[maxn], cnt, q2[maxn];
pair<int, int> b[maxn];
bool below[maxn];
struct node {
  long long a[5], siz;
} f[maxn << 3];
void pushup(long long p) {
  long long ls = p * 2, rs = p * 2 + 1;
  for (long long i = 0; i < 5; i++) f[p].a[i] = f[ls].a[i];
  f[p].siz = f[ls].siz + f[rs].siz;
  for (long long i = 0; i < 5; i++) f[p].a[(f[ls].siz + i) % 5] += f[rs].a[i];
}
long long lab(long long x) {
  if (x >= 0)
    return 1;
  else
    return 0;
}
void change(long long p, long long l, long long r, long long x, long long y) {
  if (r < x or l > x) return;
  if (l == r and l == x) {
    f[p].a[1] += y;
    f[p].siz = lab(y);
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid)
    change(p << 1, l, mid, x, y);
  else
    change(p << 1 | 1, mid + 1, r, x, y);
  pushup(p);
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    char str[3];
    scanf("%s", str);
    if (str[0] == 'a' or str[0] == 'd') {
      long long x;
      scanf("%lld", &x);
      q[i] = q2[i] = x;
      b[++cnt] = make_pair(x, i);
      if (str[0] == 'd') below[i] = true;
    } else
      q[i] = -1;
  }
  sort(b + 1, b + cnt + 1);
  long long rak = 0;
  for (long long i = 1; i <= cnt; i++) {
    if (b[i].first != b[i - 1].first) rak++;
    q[b[i].second] = rak;
  }
  for (long long i = 1; i <= n; i++) {
    if (q[i] == -1)
      printf("%lld\n", f[1].a[3]);
    else {
      if (below[i])
        change(1, 1, rak, q[i], -q2[i]);
      else
        change(1, 1, rak, q[i], q2[i]);
    }
  }
  return 0;
}
