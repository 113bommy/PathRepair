#include <bits/stdc++.h>
const int inf = (1ll << 30) - 1;
const int maxn = (int)1e5 + 10;
using namespace std;
int first[(1 << 22) + 10];
int a[100100];
int M = (1 << 22) - 1;
int n;
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    first[M ^ a[i]] = a[i];
  }
  for (int i = 0; i < 22; i++) {
    for (int m = 0; m < M; m++) {
      if (m & (1 << i))
        first[m ^ (1 << i)] = max(first[m ^ (1 << i)], first[m]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    if (first[a[i]])
      printf("%d", first[a[i]]);
    else
      printf("-1");
  }
  printf("\n");
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
