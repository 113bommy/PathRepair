#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, k;
long long t = 0, t1, t2, t3, t4, a[N], b[N];
void out(int n) {
  int ans = 0;
  for (int i = 0, j = 128; i < n; i++, j /= 2) {
    ans += j;
  }
  printf("%d", ans);
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld.%lld.%lld.%lld", &t1, &t2, &t3, &t4);
    a[i] = (t1 << 24) + (t2 << 16) + (t3 << 8) + t4;
  }
  for (int i = 1; i <= 32; i++) {
    t += (1LL << (32 - i));
    for (int j = 0; j < n; j++) {
      b[j] = (a[j] & t);
    }
    sort(b, b + n);
    int cnt = unique(b, b + n) - b;
    if (cnt == k) {
      for (int j = 0; j <= 24; j += 8) {
        out(min(8, i - j));
        printf("%c", j == 24 ? '\n' : '.');
      }
      exit(0);
    }
  }
  puts("-1");
  return 0;
}
