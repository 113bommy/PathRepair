#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, e, minimum = INT_MAX;
  cin >> n >> d >> e;
  e *= 5;
  while (n >= 0) {
    minimum = min(minimum, n % d);
    n = n - e;
  }
  cout << minimum << endl;
  return 0;
}
