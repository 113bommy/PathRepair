#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int m, d;
  cin >> m >> d;
  if ((d == 6 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 ||
                  m == 12)) ||
      (d == 7 && m != 2))
    printf("6\n");
  else if (m == 2 && d == 1)
    printf("4\n");
  else
    printf("5\n");
  return 0;
}
