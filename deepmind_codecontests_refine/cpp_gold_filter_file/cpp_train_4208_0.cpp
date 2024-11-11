#include <bits/stdc++.h>
using namespace std;
int n, A[100005], l, r, a, b;
int cnt;
inline int cmp(const int &a, const int &b) { return a > b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  sort(A + 1, A + n + 1);
  n = unique(A + 1, A + n + 1) - (A + 1);
  scanf("%d%d", &a, &b);
  while (a != b) {
    int x = a - 1;
    for (int i = 1; i <= n; i++) {
      int xx = a - (a % A[i]);
      if (xx < b) {
        A[i--] = A[--n];
        continue;
      }
      if (xx < x) x = xx;
    }
    a = x;
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
