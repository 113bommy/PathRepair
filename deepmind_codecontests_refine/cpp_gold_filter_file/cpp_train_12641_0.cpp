#include <bits/stdc++.h>
using namespace std;
const int maxn = 222222, inf = ~0U >> 1;
int A[maxn], n, m, x, y, z, p;
int main() {
  cin >> n >> m >> x >> y >> z >> p;
  x %= 4;
  y %= 2;
  z %= 4;
  while (p--) {
    int a, b;
    cin >> a >> b;
    int cnt, nn, mm;
    for (cnt = x, nn = n, mm = m; cnt--;) {
      int tx = b, ty = nn + 1 - a;
      a = tx, b = ty;
      swap(nn, mm);
    }
    if (y) b = mm + 1 - b;
    for (int cnt = z; cnt--;) {
      int ty = a, tx = mm + 1 - b;
      a = tx, b = ty;
      swap(nn, mm);
    }
    cout << a << " " << b << endl;
  }
}
