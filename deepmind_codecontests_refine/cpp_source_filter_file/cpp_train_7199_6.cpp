#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N];
bool spj;
bool check(int M) {
  for (int i = 1; i <= n; i++)
    if (b[i]) {
      if (spj && b[i] <= b[n]) continue;
      if (i - M + 1 >= b[i]) return 0;
    }
  return 1;
}
int main() {
  cin >> n;
  int L = 0, R = 2 * n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (b[i] == 1) L = i;
  }
  bool ok = 1;
  spj = 1;
  for (int i = L; i <= n; i++)
    if (i < n && a[i + 1] != a[i] + 1) ok = 0;
  if (ok == 1)
    if (check(L - n)) {
      printf("%d", L - 1);
      return 0;
    }
  L++;
  spj = 0;
  while (L < R) {
    int M = L + R >> 1;
    if (check(M))
      R = M;
    else
      L = M + 1;
  }
  printf("%d\n", R + n - 1);
  return 0;
}
