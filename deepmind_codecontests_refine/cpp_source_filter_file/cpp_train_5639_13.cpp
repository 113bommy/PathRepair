#include <bits/stdc++.h>
using namespace std;
int main() {
  int ns, max(0), a, b, cur;
  cin >> ns;
  for (int i = 0; i < ns; i++) {
    cin >> a >> b;
    cur = max - a + b;
    if (max < cur) max = cur;
  }
  cout << max;
  return 0;
}
