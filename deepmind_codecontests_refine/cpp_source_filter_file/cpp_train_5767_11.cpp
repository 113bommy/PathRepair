#include <bits/stdc++.h>
using namespace std;
long long int t, x, y, e, f, m, n, r;
char d, a, b;
int main() {
  scanf("%lld %lld %lld %lld %lld", &t, &x, &y, &e, &f);
  if (x < e) {
    m = 1;
    a = 'E';
  } else {
    m = -1;
    a = 'O';
  }
  if (y < f) {
    n = 1;
    b = 'N';
  } else {
    n = -1;
    b = 'S';
  }
  for (int i = 1; i <= t && (x != e || y != f); i++) {
    cin >> d;
    r = i;
    if (d == a && x != e)
      x += m;
    else if (d == b && y != f)
      y += n;
  }
  if (x == e && y == f)
    printf("%lld\n", r);
  else
    printf("-1\n");
}
