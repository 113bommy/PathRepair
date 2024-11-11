#include <bits/stdc++.h>
using namespace std;
int t, s, x;
int main() {
  scanf("%d%d%d", &t, &s, &x);
  x -= t;
  if (x == 1 || x < 0) {
    puts("NO");
    return 0;
  }
  x %= s;
  if (x == 0 || x == 1)
    puts("YES");
  else
    puts("NO");
  return 0;
}
