#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
long long a[maxn];
int n, k;
void input() {
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
}
void solve() {
  int cnt = 0;
  long long tmp = 0;
  for (int i = 2; i <= n; i++) {
    long long now = tmp - a[i] * (i - cnt - 1) * (n - i);
    if (now < k) {
      cnt++;
      printf("%d\n", i);
    } else
      tmp = tmp + (i - 1 - cnt) * a[i];
  }
}
int main() {
  while (scanf("%d %d", &n, &k) != EOF) {
    input();
    solve();
  }
  return 0;
}
