#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int kl = (k * l) / nl;
  int cd = c * d;
  int pnp = p / np;
  int mini = min(kl, cd);
  mini = min(mini, pnp);
  cout << mini / n << endl;
  return 0;
}
