#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N][3];
long long d[N][N];
long long dis(int a[], int b[]) {
  return (((long long)(a[0] - b[0])) * ((long long)(a[0] - b[0]))) +
         (((long long)(a[1] - b[1])) * ((long long)(a[1] - b[1]))) +
         (((long long)(a[2] - b[2])) * ((long long)(a[2] - b[2])));
}
bool check() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      d[i][j] = dis(a[i], a[j]);
    }
  }
  for (int i = 0; i < 8; ++i) {
    sort(d[i], d[i] + 8);
    if (d[i][1] == 0) return 0;
    for (int j = 2; j < 4; ++j)
      if (d[i][j] != d[i][1]) return 0;
    for (int j = 5; j < 7; ++j)
      if (d[i][j] != d[i][1] * 2) return 0;
    if (d[i][7] != d[i][1] * 3) return 0;
  }
  return 1;
}
void dfs(int p) {
  if (p >= 7) {
    if (check()) {
      puts("YES");
      for (int i = 0; i < 8; ++i) {
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
      }
      exit(0);
    }
    return;
  }
  do {
    dfs(p + 1);
  } while (next_permutation(a[p], a[p] + 3));
}
int main() {
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 3; ++j) {
      scanf("%d", a[i] + j);
    }
    sort(a[i], a[i] + 3);
  }
  dfs(0);
  puts("NO");
  return 0;
}
