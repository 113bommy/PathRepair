#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, result, i, s = 1;
  cin >> n;
  for (i = 2;; i++) {
    s = s * 3;
    if (n % s != 0) break;
  }
  result = n / s + 1;
  cout << result << endl;
  return 0;
}
