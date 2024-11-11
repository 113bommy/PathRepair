#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, a, b, flag = 0;
  cin >> n >> a >> b;
  int x, y;
  for (i = 0; i <= n / a; i++) {
    int val = (n - a * i);
    if (val % b == 0) {
      x = i;
      flag = 1;
      break;
    }
  }
  y = (n - a * x) / b;
  if (flag == 1) {
    printf("YES\n");
    cout << x << " " << y << endl;
  } else {
    printf("NO\n");
  }
  return 0;
}
