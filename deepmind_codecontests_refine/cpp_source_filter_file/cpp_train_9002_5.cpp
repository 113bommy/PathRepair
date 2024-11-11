#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    sum += (x2 - x1) * (y2 - y1);
  }
  cout << sum;
  return 0;
}
