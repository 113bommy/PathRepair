#include <bits/stdc++.h>
using namespace std;
int n;
int a[202400];
int b[1001000];
void solve() {
  int i;
  long long m = 0;
  for (i = 0; i <= 1000000; i++) {
    b[i] = 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
    m += a[i];
  }
  int ans = 0;
  for (i = 0; i < n; i++) {
    long long x = m - (long long)a[i];
    if (x <= 1000000 && x % 2 == 0) {
      if (a[i] != x / 2 && b[x / 2] > 0 || a[i] == x / 2 && b[x / 2] > 1) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  for (i = 0; i < n; i++) {
    long long x = m - (long long)a[i];
    if (x <= 2000000 && x % 2 == 0) {
      if (a[i] != x / 2 && b[x / 2] > 0 || a[i] == x / 2 && b[x / 2] > 1) {
        printf("%d ", (i + 1));
      }
    }
  }
  printf("\n");
}
int main() {
  while (scanf("%d", &n) != EOF) {
    solve();
  }
  return 0;
}
