#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int main() {
  int n, m;
  cin >> n >> m;
  int i = max(n * 2, m * 3);
  for (; i < 1000005; i++) {
    if (n + m <= i / 2 + i / 3 - i / 6) break;
  }
  cout << i << endl;
  return 0;
}
