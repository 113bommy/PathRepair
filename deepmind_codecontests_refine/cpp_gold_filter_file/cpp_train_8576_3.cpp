#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int res = n;
  res = max(res, n / 10);
  res = max(res, n / 100 * 10 + (n % 10));
  cout << res;
  return 0;
}
