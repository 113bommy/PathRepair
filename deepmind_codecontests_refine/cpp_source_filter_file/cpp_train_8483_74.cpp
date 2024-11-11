#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  cout << min(x, y) + (max(x, y) - min(x, y)) / 2 << '\n';
  return 0;
}
