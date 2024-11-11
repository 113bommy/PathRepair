#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b, sum = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> b >> a;
    sum += a - b + 1;
  }
  sum = (k - sum % k) % k;
  cout << sum << endl;
  return 0;
}
