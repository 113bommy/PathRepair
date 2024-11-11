#include <bits/stdc++.h>
using namespace std;
int t, n, s, mx;
int main() {
  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    mx = s = 0;
    for (int i = 0, a; i < n; ++i) scanf("%d", &a), s += a, mx = max(mx, a);
    s -= mx;
    if (mx > s)
      printf("T\n");
    else if ((s - mx) % 2 == 0)
      printf("HL\n");
    else
      printf("T\n");
  }
}
