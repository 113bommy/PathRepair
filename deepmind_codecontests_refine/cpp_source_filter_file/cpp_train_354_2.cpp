#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, m, a[1 << maxn];
long long ans[maxn][2];
pair<long long, const int *> Solve(const int *a, const int *b, int len) {
  static int c[1 << maxn];
  int i = 0, j = 0, k = 0;
  long long ans = 0;
  while (i < len || j < len) {
    if (i < len && (j == len || a[i] < b[j])) {
      c[k++] = a[i++];
    } else {
      ans += len - i;
      c[k++] = b[j++];
    }
  }
  return make_pair(ans, c);
}
void Sort(int *a, int n) {
  if (n == 0) {
    return;
  }
  Sort(a, n - 1);
  Sort(a + (1 << n - 1), n - 1);
  auto t = Solve(a + (1 << n - 1), a, 1 << n - 1);
  ans[n - 1][1] += t.first;
  t = Solve(a, a + (1 << n - 1), 1 << n - 1);
  ans[n - 1][0] += t.first;
  memcpy(a, t.second, (1 << n) * sizeof(int));
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < 1 << n; ++i) {
    scanf("%d", a + i);
  }
  Sort(a, n);
  int m;
  scanf("%d", &m);
  while (m--) {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
      swap(ans[i][0], ans[i][1]);
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += ans[i][0];
    }
    printf("%lld\n", sum);
  }
  return 0;
}
