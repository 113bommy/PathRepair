#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, sum = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    sum += b;
  }
  sum /= n;
  cout << sum + 5;
}
