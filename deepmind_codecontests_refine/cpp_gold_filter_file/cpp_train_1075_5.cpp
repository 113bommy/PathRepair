#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, i, dif;
  cin >> n;
  dif = n;
  while (dif & (dif - 1)) dif = dif & (dif - 1);
  vector<int> ar(n), prf(n), ch(n);
  for (i = 0; i < n; i++) cin >> ar[i];
  for (i = 0; i < n - 1; i++) {
    while (i + dif > n - 1) dif = (dif >> 1);
    ar[i + dif] += ar[i];
  }
  int sm = 0;
  for (i = 0; i < n - 1; i++) {
    sm += ar[i];
    cout << sm << "\n";
  }
  return 0;
}
