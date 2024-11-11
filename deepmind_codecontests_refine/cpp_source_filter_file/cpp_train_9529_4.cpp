#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
int n, k;
const int N = 222222;
int a[N];
int b[N];
int f[N];
bool cmp() {
  for (int i = N - 1; i >= 0; --i)
    if (a[i] != b[i]) return a[i] > b[i];
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) {
    scanf("%d", &f[i]);
    if (f[i] < 0)
      b[i] = -f[i];
    else
      a[i] = f[i];
  }
  for (int i = 0; i < N - 1; ++i) {
    a[i + 1] += a[i] / 2;
    a[i] %= 2;
    b[i + 1] += b[i] / 2;
    b[i] %= 2;
  }
  int sign = 1;
  if (!cmp()) {
    swap(a, b);
    sign = -1;
  }
  int carry = 0;
  for (int i = 0; i < N; ++i) {
    a[i] -= b[i] + carry;
    carry = a[i] < 0;
    if (carry) a[i] += 2;
  }
  int pw = 0;
  while (!a[pw]) ++pw;
  int last = pw;
  for (int i = pw + 1; i < N; ++i) {
    if (a[i] > 0) last = i;
  }
  if (last - pw > 40) {
    printf("0\n");
    return 0;
  }
  long long two = 1;
  long long factor = 0;
  for (int i = pw; i <= last; ++i) {
    if (a[i]) factor += two;
    two *= 2;
  }
  int res = 0;
  for (int i = 0; i <= min(40, pw); ++i) {
    if (factor > 1LL << 40) break;
    if (pw - i < n) {
      if (abs(f[pw - i] + sign * factor) <= k) res++;
    }
    if (pw - i == n) {
      if (abs(f[pw - i] + sign * factor) <= k &&
          abs(f[pw - i] + sign * factor) != 0)
        res++;
    }
    factor *= 2;
  }
  printf("%d\n", res);
  return 0;
}
