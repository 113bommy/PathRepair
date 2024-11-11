#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, b[N];
pair<int, int> a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].first), a[i].second = i;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i < n; ++i) b[i] = a[i + 1].first - a[i].first;
  int fail, pos, form;
  for (int i = min(n - 1, 3); i >= 2; --i) {
    if (i == 3)
      fail = 1, pos = a[2].second;
    else
      fail = 0;
    form = 0;
    for (int j = 1; j < i; ++j) form += b[j];
    b[n] = form + 1;
    for (int j = i; j < n; ++j)
      if (b[j] != form) {
        if (fail > 0 || b[j] + b[j + 1] != form)
          fail = 2;
        else
          fail = 1, pos = a[j + 1].second, ++j;
      }
    if (fail == 0) {
      printf("%d", a[1].second);
      return 0;
    }
    if (fail == 1) {
      printf("%d", pos);
      return 0;
    }
  }
  fail = 0;
  for (int i = 2; i < n; ++i)
    if (b[i] != b[2]) fail = 1;
  if (!fail) {
    printf("%d", a[1].second);
    return 0;
  }
  fail = 0;
  for (int i = 1; i < n - 1; ++i)
    if (b[i] != b[1]) fail = 1;
  if (!fail) {
    printf("%d", a[n - 1].second);
    return 0;
  }
  n == 2 ? printf("1") : printf("-1");
}
