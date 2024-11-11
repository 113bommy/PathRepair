#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], n, d;
long long x;
int getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  int i;
  for (i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int one[100010], sz, p[100010], ans[100010];
int main() {
  scanf("%d%d%I64d", &n, &d, &x);
  initAB();
  for (int i = 0; i < n; i++) p[a[i]] = i;
  for (int i = 0; i < n; i++)
    if (b[i]) one[sz++] = i;
  int cnt = 0;
  for (int i = n; i; i--) {
    for (int j = 0; j < sz && cnt <= 10000000; j++, cnt++)
      if (p[i] + one[j] < n && !ans[p[i] + one[j]]) ans[p[i] + one[j]] = i;
  }
  for (int i = 0; i < n; i++)
    if (!ans[i])
      for (int j = 0; j < sz; j++)
        if (one[j] <= i) ans[i] = max(ans[i], a[i - one[j]]);
  for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}
