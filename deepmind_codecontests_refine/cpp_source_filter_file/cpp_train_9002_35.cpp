#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  while (n--) {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    sum = (abs(x1 - y1) + 1) * (abs(x2 - y2) + 1);
  }
  cout << sum;
  return 0;
}
