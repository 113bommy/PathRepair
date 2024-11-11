#include <bits/stdc++.h>
using namespace std;
int n, opt;
int a[1005], id[1005], pos[1005];
int matrix[1005][1005];
bool cmp(int i, int j) { return a[i] < a[j]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; i++) pos[id[i]] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= a[id[i]]; j++) {
      int p = (i + j - 1) > n + 1 ? i + j - n - 2 : i + j - 1;
      matrix[p][i] = 1;
    }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) printf("%d", matrix[i][pos[j]]);
    printf("\n");
  }
  return 0;
}
