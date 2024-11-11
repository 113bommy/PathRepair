#include <bits/stdc++.h>
using namespace std;
int n, x1, x2, x3, x4, sum;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> x2 >> x3 >> x4;
    sum += (x4 - x2 + 1) * (x3 - x1 + 1);
  }
  cout << sum;
}
