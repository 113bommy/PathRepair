#include <bits/stdc++.h>
using namespace std;
int n, m, sum1, sum2, x, a, b;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x == -1)
      sum1++;
    else
      sum2++;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    if ((b - a + 1) % 2 != 0)
      cout << "0" << endl;
    else {
      if ((sum1 >= (b - a + 1) / 2) && sum2 >= (b - a + 1) / 2)
        cout << "1" << endl;
      else
        cout << "0" << endl;
    }
  }
  return 0;
}
