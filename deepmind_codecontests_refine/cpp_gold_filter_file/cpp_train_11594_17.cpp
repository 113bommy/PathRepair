#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, t = 1, it, s, i, ac, a[60] = {0}, b[60] = {0};
  cin >> s >> k;
  a[1] = 1;
  a[2] = 1;
  ac = 2;
  it = k;
  while (a[ac] < s) {
    ac++;
    for (i = 1; i <= it; i++) {
      a[ac] += a[ac - i];
      if (ac - i == 1) i = it + 1;
    }
  }
  ac++;
  while (s != 0) {
    ac--;
    if (a[ac] <= s) {
      b[t] = a[ac];
      t++;
      s -= a[ac];
    }
  }
  t--;
  if (t > 0) {
    cout << t + 1 << endl;
  }
  for (i = 1; i <= t; i++) cout << b[i] << " ";
  cout << "0";
}
