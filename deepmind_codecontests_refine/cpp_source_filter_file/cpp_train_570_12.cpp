#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
const int MAXN = 5e5 + 10;
int n, cnt, ans;
int a[MAXN];
int main() {
  scanf("%d %d", &n, a + 1);
  for (int i = 2; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] != a[i - 1])
      cnt++;
    else {
      if (cnt <= 1) {
        cnt = 0;
        continue;
      }
      if (cnt % 2 == 0) {
        int start = i - cnt - 1;
        for (int j = start; j < i; j++) a[j] = a[start];
      } else {
        int start = i - cnt;
        for (int j = start; j <= start + cnt / 2; j++) a[j] = a[start];
        for (int j = start + cnt / 2 + 1; j < i; j++) a[j] = a[i];
      }
      ans = max(ans, cnt / 2), cnt = 0;
    }
  }
  if (cnt <= 1) {
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
  }
  if (cnt % 2 == 0) {
    int start = n - cnt - 1;
    for (int j = start; j < n; j++) a[j] = a[start];
  } else {
    int start = n - cnt;
    for (int j = start; j <= start + cnt / 2; j++) a[j] = a[start];
    for (int j = start + cnt / 2 + 1; j < n; j++) a[j] = a[n];
  }
  ans = max(ans, cnt / 2);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}
