#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np, mini = 10000000000;
  {
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    mini = min((c * d) / n, mini);
    mini = min((p / np) / n, mini);
    mini = min(((k * l) / nl) / 3, mini);
    cout << mini;
  }
  return 0;
}
