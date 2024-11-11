#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, r, R;
  cin >> n >> R >> r;
  double sum = acos(-1) / n;
  sum = sin(sum);
  if ((n == 1 && r <= R) || sum * (R - r) - r >= 0 ||
      fabs(sum * (R - r) - r) <= 0.000000001)
    printf("YES\n");
  else
    printf("NO\n");
}
