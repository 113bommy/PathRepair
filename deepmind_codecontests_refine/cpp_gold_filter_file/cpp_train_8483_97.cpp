#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, d, c1 = 0, c2 = 0, sum = 0;
  scanf("%d%d", &a, &b);
  c1 = min(a, b);
  if (a > b) {
    sum = a - b;
  } else {
    sum = b - a;
  }
  d = sum;
  while (sum - 2 >= 0) {
    sum = sum - 2;
    c2++;
  }
  if (d - 2 >= 0) {
    cout << c1 << " " << c2 << endl;
    return 0;
  } else {
    cout << c1 << " " << 0 << endl;
    return 0;
  }
  return 0;
}
