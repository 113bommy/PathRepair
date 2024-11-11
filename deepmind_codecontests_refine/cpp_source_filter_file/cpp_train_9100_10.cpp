#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int sum = 0, y;
  for (int i = 0; i < n; i++) {
    cin >> y;
    sum += y;
  }
  if (sum == 0) {
    cout << "0\n";
    return 0;
  }
  if (abs(sum) <= x) {
    cout << "1\n";
    return 0;
  } else if (sum < 0)
    sum = -sum;
  cout << ceil(sum / x);
  return 0;
}
