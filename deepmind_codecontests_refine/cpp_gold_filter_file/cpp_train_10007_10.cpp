#include <bits/stdc++.h>
double const PI = 4 * atan(1);
using namespace std;
char s[10];
int main() {
  int n = 0, m = 0, k, A, B, i, j, u, v;
  scanf("%s", s);
  A = (s[0] - '0') * 10 + s[1] - '0';
  B = (s[3] - '0') * 10 + s[4] - '0';
  for (i = A; i < 24; i++) {
    if (n > 0) break;
    u = i / 10;
    v = i % 10;
    m = v * 10 + u;
    if (m < 60) {
      if ((i == A && m > B) || i > A) {
        n = i;
        break;
      }
    }
  }
  if (n == 0) m = 0;
  printf("%02d:%02d", n, m);
}
