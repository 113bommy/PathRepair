#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  int mn = 1, s = 1;
  for (int i = 1; i < l; i++) {
    s *= 2;
    mn += s;
  }
  mn += (n - l);
  int mx = 1, t, sum = 1;
  for (int i = 1; i < r; i++) {
    sum *= 2;
    mx += sum;
    t = sum;
  }
  mx += (t * (n - r));
  cout << mn << " " << mx << '\n';
  return 0;
}
