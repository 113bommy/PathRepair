#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, m1;
  scanf("%d%d", &n, &m);
  m1 = m;
  int a[n], i1;
  for (i1 = 0; i1 < n; i1++) a[i1] = 0;
  while (m1--) {
    long long int i, j, k, l;
    cin >> l;
    j = 0;
    for (i = 1; i < n; i++) {
      cin >> k;
      if (k > l) {
        l = k;
        j = i;
      }
    }
    a[j]++;
  }
  int ans = 0;
  for (i1 = 1; i1 < n; i1++) {
    if (a[i1] > a[ans]) {
      ans = i1;
    }
  }
  printf("%d", ans + 1);
  return 0;
}
