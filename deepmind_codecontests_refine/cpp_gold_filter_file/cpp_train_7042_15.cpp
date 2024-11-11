#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, aa, b, m, n, ret = 0;
  cin >> n >> m >> a >> b;
  a--;
  aa = a;
  b--;
  n--;
  if (a % m != 0) {
    ret++;
    a = ((a + m - 1) / m) * m;
  }
  if (b < a) {
  } else {
    if (b == n || b % m == m - 1 || (b - aa + 1) % m == 0) {
      ret += 1;
    } else {
      if (b - a >= m) {
        ret += 2;
      } else {
        ret++;
      }
    }
  }
  cout << ret << endl;
  return 0;
}
