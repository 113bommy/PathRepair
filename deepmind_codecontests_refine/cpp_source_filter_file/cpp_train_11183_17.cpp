#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int t;
  cin >> t;
  sort(a, a + n);
  int max = 0, p, c;
  for (int j = 0; j < n; j++) {
    p = a[j] + t;
    c = 0;
    for (int i = j; a[i] <= p; i++) {
      c = c + 1;
    }
    if (c > max) max = c;
  }
  printf("%d", max);
  return 0;
}
