#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string X, Y;
  cin >> n;
  X = "";
  int p, m, a, b, c, d, e, tmp;
  int max = -1000000000;
  for (int i = 0; i < n; i++) {
    cin >> Y >> p >> m >> a >> b >> c >> d >> e;
    tmp = p * 100 - 50 * m + a + b + c + d;
    if (max < tmp) {
      max = tmp;
      X = Y;
    }
  }
  cout << X << endl;
  return 0;
}
