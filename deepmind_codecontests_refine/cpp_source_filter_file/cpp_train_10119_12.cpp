#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 8;
const int INF = 10000;
int a[MAX_N][MAX_N];
int n, k;
int p[MAX_N];
int ans;
int main() {
  scanf("%d %d\n", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      char c;
      scanf("%c", &c);
      a[i][j] = c - '0';
    }
    scanf("\n");
  }
  for (int i = 0; i < k; i++) p[i] = i;
  ans = INF;
  do {
    int mi = INF, ma = -INF;
    for (int i = 0; i < n; i++) {
      int x = 0;
      for (int j = 0; j < k; j++) (x *= 10) += a[i][p[j]];
      ma = max(ma, x);
      mi = min(mi, x);
    }
    ans = min(ans, ma - mi);
  } while (next_permutation(p, p + k));
  printf("%d\n", ans);
}
