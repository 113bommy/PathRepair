#include <bits/stdc++.h>
using namespace std;
double n, a;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a;
  double dx = (180 / n), menor = 2000000000;
  int pulo, cnt = 3;
  for (double i = dx; i <= (180 * (n - 2) / n); i += dx, cnt++) {
    if (abs(i - a) < menor) {
      menor = abs(i - a);
      pulo = cnt;
    }
  }
  cout << pulo << " " << 1 << " " << 2 << "\n";
}
