#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char a[N];
int main() {
  int n, q;
  cin >> n >> q;
  int s[2] = {0, 1};
  for (int i = 0; i < q; ++i) {
    int tp, x;
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d", &x);
      x = (-x + n) % n;
      if (x % 2 == 0) {
        s[0] = (s[0] + x) % n;
        s[1] = (s[1] + x) % n;
      } else {
        --x;
        int old0 = s[0];
        int old1 = s[1];
        s[0] = (old1 + x) % n;
        s[1] = (old0 + x + 2) % n;
      }
    } else
      swap(s[0], s[1]);
  }
  for (int i = 0; i < n; i += 2) {
    a[i] = s[0];
    s[0] = (s[0] + 2) % n;
    a[i + 1] = s[1];
    s[1] = (s[1] + 2) % n;
  }
  for (int i = 0; i < n; ++i) printf("%d ", a[i] + 1);
  return 0;
}
