#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, vi[101], res[101], ansmin = 10000000, ansmax;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &vi[i]);
  for (int i = 0; i < n - 1; i++) res[i] = vi[i + 1] - vi[i];
  for (int i = 0; i < n - 2; i++) {
    ansmax = res[i] + res[i + 1];
    for (int j = 0; j < n - 1; j++) ansmax = max(ansmax, res[j]);
    ansmin = min(ansmin, ansmax);
  }
  printf("%d\n", ansmin);
  return 0;
}
