#include <bits/stdc++.h>
using namespace std;
int a[1000001];
char was[1000001];
int main() {
  cin.sync_with_stdio(false);
  int n, msk = 1;
  cin >> n;
  cout << (1LL * n * (n + 1)) << endl;
  for (int i = n; i > 0; i--) {
    if (was[i]) continue;
    for (msk = 1; msk <= i; msk <<= 1)
      ;
    msk--;
    int el = msk ^ i;
    if (!was[el]) {
      a[i] = el;
      a[el] = i;
      was[i] = was[el] = 1;
    }
  }
  if (!was[0]) {
    for (int i = 1; i <= n; i++)
      if (!was[i]) a[0] = i, a[i] = 0;
  }
  for (int i = 0; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
