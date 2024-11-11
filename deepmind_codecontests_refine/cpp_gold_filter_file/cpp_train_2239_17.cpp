#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, min1, min2;
  cin >> n >> m >> k;
  min1 = min(n * 2 + m * 2, n + m + k);
  min2 = min(2 * n + 2 * k, 2 * m + 2 * k);
  cout << min(min1, min2) << endl;
}
