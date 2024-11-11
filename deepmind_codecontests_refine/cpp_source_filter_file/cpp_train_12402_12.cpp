#include <bits/stdc++.h>
using namespace std;
int n, m, bit, tmp, cnt, a[200002], b[18];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    m = max(m, a[i]);
    a[i] ^= a[i - 1];
  }
  if (a[n] == 0)
    printf("-1\n");
  else {
    bit = log(m) / log(2);
    for (int i = 1; i <= n; i++) {
      m = a[i];
      for (int j = bit; j >= 0; j--)
        if ((1 << j) & m) {
          if (b[j] == 0) {
            b[j] = m;
            cnt++;
            break;
          } else
            m ^= b[j];
        }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
