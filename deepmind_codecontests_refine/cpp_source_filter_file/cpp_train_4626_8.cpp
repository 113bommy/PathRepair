#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[101] = {0};
  int x, x1, y1, y;
  cin >> x >> y;
  x1 = x;
  y1 = y;
  for (int i = x; i <= y; i++) {
    a[i] = -1;
  }
  n--;
  while (n--) {
    cin >> x >> y;
    for (int i = x; i < y; i++) {
      a[i] = 1;
    }
  }
  int sum = 0, flag = 0;
  for (int i = x1; i < y1; i++) {
    if (a[i] == 1) {
      flag = i;
      break;
    }
  }
  for (int i = x1; i <= y1; i++) {
    if (a[i] == -1) sum++;
  }
  if (sum == y1 - x1 + 1) {
    cout << y1 - x1;
    return 0;
  }
  cout << sum;
  return 0;
}
