#include <bits/stdc++.h>
using namespace ::std;
int main() {
  int w, a, b;
  cin >> w >> a >> b;
  cout << min(abs(a - b) - w, 0) << '\n';
}
