#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, x, y, count = 0;
  cin >> n >> m;
  for (x = 1; x <= n; x++) count += (int)(m + x) / 5 - (int)(x / 5);
  cout << count;
  return 0;
}
