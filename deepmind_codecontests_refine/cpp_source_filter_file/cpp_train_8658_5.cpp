#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, l, r;
  cin >> n >> l >> r;
  long long int s = 2;
  long long int mn = n - (l - 1);
  for (int i = 1; i <= l - 1; i++) {
    mn += s;
    s += 2;
  }
  s = 2;
  long long int mx = 1;
  for (int i = 1; i <= r - 1; i++) {
    mx += s;
    s *= 2;
  }
  s = s / 2;
  if (n - r > 0) mx += (n - r) * s;
  cout << mn << " " << mx << "\n";
  return 0;
}
