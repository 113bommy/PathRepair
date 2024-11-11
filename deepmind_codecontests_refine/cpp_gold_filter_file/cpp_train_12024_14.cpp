#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 1;
int A[nax];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    A[x]++;
  }
  for (int i = nax - 1; i > 0; i--) {
    if (!A[i]) continue;
    for (int j = i + i; j < nax; j += i) A[i] = max(A[i], 1 + A[j]);
  }
  int ans = A[1];
  for (int i = 2; i < nax; i++) ans = max(ans, A[i]);
  printf("%d\n", ans);
  return 0;
}
