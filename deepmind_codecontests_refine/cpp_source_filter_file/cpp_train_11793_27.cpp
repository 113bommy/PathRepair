#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, r, R;
  while (cin >> n >> R >> r) {
    if ((n == 2 && R >= r + r) || (n == 1 && R >= r))
      printf("YES\n");
    else if (r + r > R)
      printf("NO\n");
    else if ((R - r) * sin(acos(-1) / n) >= r)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
