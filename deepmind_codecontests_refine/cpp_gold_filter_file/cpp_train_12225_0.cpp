#include <bits/stdc++.h>
using namespace std;
int long long p, x, i, j, b, d[1000006];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> p >> x;
  for (i = 1; i <= 9; i++) {
    d[p] = i;
    for (j = p - 1; j > 0; j--) {
      b = d[j + 1] / 10;
      d[j + 1] %= 10;
      d[j] = b + d[j + 1] * x;
    }
    b = d[1] / 10;
    d[1] %= 10;
    if (d[1] != 0 && d[1] * x + b == d[p]) {
      for (j = 1; j <= p; j++) cout << d[j];
      return 0;
    }
  }
  cout << "Impossible";
}
