#include <bits/stdc++.h>
using namespace std;
int main() {
  int ar[110], n, m, a, s, d, i, b, h, j, k;
  scanf("%d %d", &n, &k);
  a = 0x3F3F3F3F;
  s = 0;
  for (m = 1; m <= n; m++) {
    cin >> ar[m];
    a = min(a, ar[m]);
    s = max(s, ar[m]);
  }
  if (k < s - a) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (b = 1; b <= n; b++) {
      for (d = 1; d <= a; d++) {
        printf("1 ");
      }
      for (i = 1, j = 1; i <= ar[b] - a; i++, j++) {
        printf("%d ", j);
      }
      printf("\n");
    }
  }
  return 0;
}
