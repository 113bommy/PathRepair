#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e6 + 10;
int n, l, t, a[N];
int main() {
  scanf("%d %d %d", &n, &l, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[n + i] = a[i] + l;
  }
  long long ans = 1LL * (t / l) * n * (n - 1);
  t %= l;
  for (int i = n, j = 0, k = 0; i < n + n; i++) {
    while (j <= i - n) {
      j++;
    }
    while (k <= i - n) {
      k++;
    }
    while (j < i && a[i] - a[j] + l > t + t) {
      j++;
    }
    while (k < i && a[i] - a[k] > t + t) {
      k++;
    }
    ans += i - j;
    ans += i - k;
  }
  printf("%.10f\n", 0.25 * ans);
  return 0;
}
