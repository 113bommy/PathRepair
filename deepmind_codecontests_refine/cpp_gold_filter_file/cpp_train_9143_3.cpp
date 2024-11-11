#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(min(b, d) - max(a, c), 0) << '\n';
  return 0;
}
