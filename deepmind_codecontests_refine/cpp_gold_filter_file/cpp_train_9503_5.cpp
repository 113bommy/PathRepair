#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long unsigned int res = 1;
  if (n == 2) {
    cout << "1" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    res = res * i;
  }
  res = res / n;
  res = 2 * res / (n);
  cout << res << endl;
  return 0;
}
