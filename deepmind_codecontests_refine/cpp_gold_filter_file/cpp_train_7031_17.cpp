#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;
int main() {
  cin >> c >> d >> e >> f >> a >> b;
  cout << max(0, min(min(min(c - 1, d - 1), min(e - 1, f - 1)), b) - a + 1);
  return 0;
}
