#include <bits/stdc++.h>
using namespace std;
char str[111][111];
int c[111];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    int odd, even;
    odd = even = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (x % 2 == 0)
        even++;
      else
        odd++;
    }
    int ans;
    if (n == m) {
      if (odd & 1)
        ans = 0;
      else
        ans = 1;
    } else if ((n - m) % 2) {
      if (odd <= (n - m) / 2)
        ans = 1;
      else if (m % 2 == 0 && even <= (n - m) / 2)
        ans = 1;
      else
        ans = 0;
    } else {
      if (m % 2 == 1 && even <= (n - m) / 2)
        ans = 0;
      else
        ans = 1;
    }
    puts(ans ? "Daenerys" : "Stannis");
  }
  return 0;
}
