#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int min = 1000000;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (k % x == 0 && k / x < min) min = k / x;
  }
  cout << min << endl;
  return 0;
}
