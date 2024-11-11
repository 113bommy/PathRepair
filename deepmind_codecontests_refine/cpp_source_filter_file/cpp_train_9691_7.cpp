#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, cnt = 2, A[105];
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= n; i++) {
    if (A[i + 1] - A[i] >= m * 2) cnt++;
    if (A[i + 1] - A[i] > m * 2) cnt++;
  }
  printf("%d", cnt);
  return 0;
}
