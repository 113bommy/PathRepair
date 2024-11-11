#include <bits/stdc++.h>
using namespace std;
long long int n, m, ta, tb, k;
long long int a[2 * 100010], b[2 * 100010];
void input() {
  long long int i, j;
  scanf("%lld %lld", &n, &m), scanf("%lld %lld %lld", &ta, &tb, &k);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (i = 0; i < m; i++) {
    scanf("%lld", &b[i]);
  }
}
void solve() {
  long long int i, j, mx = -1;
  if (k >= n) {
    printf("%d", -1);
    puts("");
    return;
  }
  for (i = 0; i <= k; i++) {
    long long int idx = (long long int)(lower_bound(b, b + m, a[i] + ta) - b);
    if (m - idx <= k - i) {
      printf("%d", -1);
      puts("");
      return;
    }
    mx = max(b[idx + k - i] + tb, mx);
  }
  printf("%lld", mx);
  puts("");
}
int main() {
  input();
  solve();
}
