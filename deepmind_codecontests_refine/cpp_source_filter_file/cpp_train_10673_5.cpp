#include <bits/stdc++.h>
using namespace std;
int A[5010], s[5010], f[5010];
int main() {
  int n, i, j, ans;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (i = 1; i <= n; i++) {
    memset(s, 0, sizeof(s));
    ans = 0;
    for (j = i; j <= n; j++) {
      s[A[j]]++;
      if (s[A[j]] > s[ans] || (s[A[j] == s[ans]] && A[j] < ans)) ans = A[j];
      f[ans]++;
    }
  }
  for (i = 1; i <= n; i++) printf("%d ", f[i]);
  printf("\n");
  return 0;
}
