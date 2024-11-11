#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y, id;
  bool operator<(const node &T) const { return y < T.y; }
};
long long n, sqn, last;
long long a[300005];
long long ans[300005];
long long sum[300005];
long long q;
node qu[300005];
void f(int l) {
  for (int i = n; i > 0; i--) {
    sum[i] = a[i];
    if (i + l <= n) sum[i] += sum[i + l];
  }
  return;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sqn = sqrt(n);
  scanf("%lld", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%lld%lld", &qu[i].x, &qu[i].y);
    qu[i].id = i;
  }
  sort(qu + 1, qu + q + 1);
  last = 1;
  qu[q + 1].y = 1e+9;
  for (int i = 2; i <= q + 1; i++) {
    if (qu[i].y != qu[i - 1].y) {
      f(qu[i - 1].y);
      for (int j = last; j < i; j++) {
        ans[qu[j].id] = sum[qu[j].x];
      }
      last = i;
      if (qu[i].y >= sqn) break;
    }
  }
  for (int i = last; i <= q; i++) {
    for (int j = qu[i].x; j <= n; j += qu[i].y) {
      ans[qu[i].id] += a[j];
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
