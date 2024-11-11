#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, a, b, tx = 0, ty = 0;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a >> b;
    tx += a;
    ty += b;
  }
  cout << tx / n << " " << ty / n << endl;
  return 0;
}
