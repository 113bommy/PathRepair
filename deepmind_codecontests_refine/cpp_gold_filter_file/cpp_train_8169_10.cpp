#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 31) - 1;
int A[100005], n, flag;
int find(int pos, int val) {
  if (pos == 0) return 0;
  if (val == 1) {
    if (A[pos] == 1) {
      printf("YES\n");
      for (int i = 1; i < n; ++i) printf("%d->", A[i]);
      printf("%d\n", A[n]);
      return 1;
    }
    if (pos > 1 && A[pos] == 0 && A[pos - 1] == 0) {
      printf("YES\n");
      for (int i = 1; i < pos - 1; ++i) printf("%d->", A[i]);
      printf("(0->0)->");
      for (int i = pos + 1; i < n; ++i) printf("%d->", A[i]);
      printf("%d\n", A[n]);
      return 1;
    }
    flag = pos;
    return find(pos - 1, 0);
  } else {
    if (A[pos] == 0) {
      printf("YES\n");
      for (int i = 1; i < pos; ++i) printf("%d->", A[i]);
      printf("(");
      printf("%d->(", A[pos]);
      for (int i = pos + 1; i <= flag; ++i) {
        printf("%d", A[i]);
        if (i != flag) printf("->");
      }
      printf("))->%d\n", A[n]);
      ;
      return 1;
    }
    return find(pos - 1, 0);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  if (A[n] != 0) {
    printf("NO\n");
    return 0;
  }
  if (n == 1) {
    printf("YES\n0\n");
    return 0;
  }
  if (!find(n - 1, 1)) printf("NO\n");
  return 0;
}
