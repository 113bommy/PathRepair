#include <bits/stdc++.h>
using namespace std;
int A[310000], B[300];
int s;
bool cha(int l, int r, int k) {
  bool cha = 1;
  for (int i = 0; i < s; i++) {
    bool cha1 = 1;
    for (int j = 0; j + l <= r; j++)
      if (A[j + l] < B[(i + j) % s]) {
        cha1 = 0;
        break;
      }
    if (cha1) {
      cha = 0;
      break;
    }
  }
  return cha;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    for (int i = 0; i <= k; i++) B[i] = i;
    int m = k;
    s = k;
    while (m != 1) {
      B[++s] = --m;
    }
    s++;
    bool ch = 1;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
      A[i] = l - A[i];
      if (A[i] < 0) ch = 0;
    }
    if (!ch) {
      printf("No\n");
      continue;
    }
    A[0] = 9999999999;
    int to = 1;
    for (int i = 2; i <= n; i++)
      if (A[i] >= k) {
        if (cha(to, i, k)) {
          ch = 0;
          break;
        }
        to = i;
      }
    if (cha(to, n, k)) ch = 0;
    if (ch)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
