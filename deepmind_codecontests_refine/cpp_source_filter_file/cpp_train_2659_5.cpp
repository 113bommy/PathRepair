#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, a, sum = 0;
  cin >> n;
  cin >> h;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a < h)
      sum += 1;
    else
      sum += 2;
  }
  cout << sum;
  return 0;
}
