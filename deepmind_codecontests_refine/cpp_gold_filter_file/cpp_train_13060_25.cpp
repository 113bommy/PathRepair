#include <bits/stdc++.h>
using namespace std;
int check_composite(long int x, long int y) {
  int s = 0, t = 0;
  for (int i = 2; i < x; i++) {
    if (x % i == 0) s++;
  }
  for (int j = 2; j < y; j++) {
    if (y % j == 0) t++;
  }
  if (s > 0 && t > 0) {
    cout << x << " " << y;
    exit(0);
  }
}
int main() {
  long int n, x, y, i, j;
  cin >> n;
  for (i = 4; i <= n / 2; i++) {
    j = n - i;
    check_composite(i, j);
  }
  return 0;
}
