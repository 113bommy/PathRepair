#include <bits/stdc++.h>
using namespace std;
struct point {
  int x;
  int y;
};
bool operator<(const point &a, const point &b) { return (a.x < b.x); }
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int tc;
int a[100][100], b[100][100];
int main() {
  int n, j, i, k, o;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    for (j = 0; j < k; j++) {
      scanf("%d", &o);
      a[i][o] = 1;
    }
  }
  int l, p;
  int flag;
  for (i = 0; i < n; i++) {
    for (l = 0; l < n; l++)
      for (p = 0; p < 100; p++) b[l][p] = a[l][p];
    for (l = 0; l < n; l++) {
      if (l != i) {
        for (p = 0; p < 100; p++)
          if (b[i][p] == 1 && b[l][p] == 1) b[l][p] = 0;
      }
      flag = 1;
      for (p = 0; p < 100; p++) {
        if (b[l][p] == 1) {
          flag = 0;
          break;
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
