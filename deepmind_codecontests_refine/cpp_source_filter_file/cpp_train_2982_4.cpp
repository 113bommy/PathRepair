#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], p = 1, sta[N], top;
int main() {
  scanf("%d%d", &n, &m);
  sta[0] = 1e9;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    if (a[i] > sta[top]) return puts("-1"), 0;
    sta[++top] = a[i];
    while (sta[top] == p) top--, p++;
  }
  for (int i = 1; i <= m; i++) printf("%d ", a[i]);
  while (top) {
    for (int i = sta[top] - 1; i; i--) printf("%d ", i);
    p = sta[top];
    while (sta[top] == p) top--, p++;
  }
  for (int i = n; i >= p; i--) printf("%d ", i);
  return 0;
}
