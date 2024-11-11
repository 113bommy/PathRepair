#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, res1 = 0, res2 = 0;
  cin >> a >> b;
  res1 = min(a, b);
  res2 = (max(a, b) - min(a, b)) / 2;
  cout << res1 << " " << res2;
  return 0;
}
