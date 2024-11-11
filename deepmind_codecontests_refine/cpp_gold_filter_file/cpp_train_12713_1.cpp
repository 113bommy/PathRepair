#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, j, total, cnt;
  cin >> n >> k;
  double r, g, b;
  r = ceil((n * 2.0) / k);
  g = ceil((n * 5.0) / k);
  b = ceil((n * 8.0) / k);
  cout << int(r + g + b) << endl;
  return 0;
}
