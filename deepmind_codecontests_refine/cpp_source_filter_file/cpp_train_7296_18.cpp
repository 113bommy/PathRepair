#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 2 * N;
int a[M];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    printf("1\n");
    fflush(stdout);
    int first = 0;
    scanf("%d", &first);
    if (first == 0) return 0;
    if (first == 1) {
      a[i] = 1;
    } else
      a[i] = 0;
  }
  int l = 1, r = n;
  int t = 0;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    printf("%d\n", mid);
    fflush(stdout);
    int first = 0;
    scanf("%d", &first);
    if (first == 0) return 0;
    if (!a[t]) first = -first;
    t = (t + 1) % m;
    if (first == -1)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", r);
  fflush(stdout);
  int first;
  scanf("%d", &first);
  return 0;
}
