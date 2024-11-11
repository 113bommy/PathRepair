#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v) cin >> x;
  sort(v.begin(), v.end());
  int big = n - 1, sml = (n - 1) / 2;
  while (sml >= 0) {
    if (v[big] >= 2 * v[sml])
      n--, big--, sml--;
    else
      sml--;
  }
  cout << n << '\n';
  return 0;
}
