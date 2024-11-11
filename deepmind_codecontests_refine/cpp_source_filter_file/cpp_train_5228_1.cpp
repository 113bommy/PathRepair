#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    if (n % k > k / 2)
      cout << n / k * k + k / 2;
    else
      cout << n << endl;
  }
  return 0;
}
