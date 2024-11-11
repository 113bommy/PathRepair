#include <bits/stdc++.h>
using namespace std;
int a[200001], l[200001], r[200001], lpos[31], rpos[31];
map<int, int> m;
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < 31; ++i) {
    lpos[i] = -1;
    rpos[i] = n;
  }
  for (i = 0; i < n; ++i) {
    l[i] = m.count(a[i]) > 0 ? m[a[i]] : -1;
    for (j = 0; j < 31; ++j) {
      if (!(a[i] & (1 << j))) {
        l[i] = (((l[i]) > (lpos[j])) ? (l[i]) : (lpos[j]));
      }
    }
    for (j = 0; j < 31; ++j) {
      if (a[i] & (1 << j)) {
        lpos[j] = i;
      }
    }
    m[a[i]] = i;
  }
  for (i = n - 1; i >= 0; --i) {
    r[i] = n;
    for (j = 0; j < 31; ++j) {
      if (!(a[i] & (1 << j))) {
        r[i] = (((r[i]) > (rpos[j])) ? (rpos[j]) : (r[i]));
      }
    }
    for (j = 0; j < 31; ++j) {
      if (a[i] & (1 << j)) {
        rpos[j] = i;
      }
    }
  }
  long long sum = 1ll * n * (n - 1) / 2;
  for (i = 0; i < n; ++i) {
    sum -= (i - l[i] - 1ll) + (r[i] - i - 1) + (i - l[i] - 1) * (r[i] - i - 1);
  }
  printf("%I64d\n", sum);
  return 0;
}
