#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int K = 30;
int n, k;
int a[N], b[N];
int step[K][N];
int main() {
  scanf("%d%d", &n, &k);
  a[0] = 0;
  for (int i = 1; i < n; ++i) {
    a[i] = 1;
  }
  int *p1 = a, *p2 = b;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      ;
      ;
      int pos = upper_bound(p1, p1 + n, j - p1[j]) - p1;
      pos--;
      ;
      p2[j] = p1[j] + p1[pos];
      step[i][j] = n - pos;
    }
    swap(p1, p2);
  }
  for (int i = 0; i < k; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      printf("%d%c", step[i][j], " \n"[j == 0]);
    }
  }
  return 0;
}
