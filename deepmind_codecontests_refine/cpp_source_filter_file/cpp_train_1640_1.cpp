#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, fee, now, more, des;
  cin >> n >> m >> a >> b;
  fee = a + b;
  if (n % m == 0) {
    cout << 0;
    return 0;
  }
  now = n / m;
  des = (n - now * m) * b;
  more = ((now + 1) * m - n) * a;
  if (des < more)
    cout << des;
  else
    cout << more;
  return 0;
}
