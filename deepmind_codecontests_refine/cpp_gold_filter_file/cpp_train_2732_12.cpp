#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int vis[N];
int a[N];
int b[N];
int sum[N];
int main() {
  int cnt = 0;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      for (int j = i + i; j < N; j += i) {
        vis[j] = 1;
      }
      a[++cnt] = i;
    }
  }
  for (int i = 1; i <= 132; i++) {
    b[i] = 1;
    while (1ll * b[i] * a[i] * b[i] * a[i] <= 2e6) {
      b[i] *= a[i];
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    long long ans = 1;
    for (int i = 1; i <= 132; i += 6) {
      printf("? %lld\n",
             1ll * b[i] * b[i + 1] * b[i + 2] * b[i + 3] * b[i + 4] * b[i + 5]);
      fflush(stdout);
      long long temp;
      scanf("%lld", &temp);
      for (int j = i; j < i + 6; j++) {
        sum[j] = 1;
        while (temp % a[j] == 0) {
          sum[j]++;
          temp /= a[j];
        }
        ans *= sum[j];
      }
    }
    printf("! %lld\n", max(ans * 2, ans + 7));
    fflush(stdout);
  }
}
