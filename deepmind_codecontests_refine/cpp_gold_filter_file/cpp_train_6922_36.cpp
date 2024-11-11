#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n1, n2, k, m, mn1 = 999999, mn2 = 999999, jm;
  cin >> n1 >> n2 >> k >> m;
  long long int a[n1 + 1], b[n2 + 1];
  for (i = 0; i < n1; i++) {
    cin >> a[i];
  }
  for (j = 0; j < n2; j++) {
    cin >> b[j];
    if (j == n2 - m) jm = b[j];
  }
  for (i = 0; i < k; i++) {
    if (a[i] >= jm) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}
