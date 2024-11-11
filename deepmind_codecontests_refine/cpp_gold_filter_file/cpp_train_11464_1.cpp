#include <bits/stdc++.h>
using namespace std;
int n, l[1010], r[1010], v[1010];
bool ok() {
  int le, gr;
  for (int i = 1; i <= n; i++) {
    le = 0;
    gr = 0;
    for (int j = 1; j < i; j++) {
      if (v[j] > v[i]) le++;
    }
    for (int j = i + 1; j <= n; j++) {
      if (v[j] > v[i]) gr++;
    }
    if (le != l[i] || gr != r[i]) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
  for (int i = 1; i <= n; i++) v[i] = n - (l[i] + r[i]);
  if (ok()) {
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", v[i]);
    printf("\n");
  } else
    printf("NO\n");
  return 0;
}
