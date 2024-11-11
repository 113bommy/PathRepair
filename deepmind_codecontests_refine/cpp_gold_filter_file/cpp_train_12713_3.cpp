#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, k;
  cin >> n >> k;
  cout << int64_t(ceil((2 * n) / k) + ceil((5 * n) / k) + ceil((8 * n) / k));
  return 0;
}
