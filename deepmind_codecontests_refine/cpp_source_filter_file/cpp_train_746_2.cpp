#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll m;
ll sum;
int idx[1000001];
template <typename T>
inline T read() {
  T x = 0;
  T multiplier = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      multiplier = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch & 15);
    ch = getchar();
  }
  return x * multiplier;
}
int main() {
  n = read<int>(), m = read<int>();
  sum = 1LL * n * (n + 1) >> 1;
  if (sum > m) {
    puts("-1");
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    idx[i] = i;
  }
  for (int i = n; i >= (n >> 1) + 1; i--) {
    if (sum + i - (n - i + 1) <= m) {
      sum += i - (n - i + 1);
      swap(idx[i], idx[n - i + 1]);
    } else {
      swap(idx[i], idx[i - (m - sum)]);
      sum = m;
    }
  }
  printf("%lld\n", sum);
  for (int i = 1; i <= n; i++) {
    printf("%d ", i);
  }
  puts("");
  for (int i = 1; i <= n; i++) {
    printf("%d ", idx[i]);
  }
  puts("");
  return 0;
}
