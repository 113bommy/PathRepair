#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  int a, b, c, n;
  while (cin >> n >> a >> b >> c) {
    n--;
    if (!n) {
      cout << 0 << endl;
      continue;
    }
    int sum = 0;
    sum += min(a, b);
    n--;
    sum += min(min(a, b), c) * n;
    cout << sum << endl;
  }
  return 0;
}
