#include <bits/stdc++.h>
using namespace std;
long long mas[100010];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  long long mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> mas[i];
    mx = max(mx, mas[i]);
  }
  long long l = mx, r = 1000000000000000000;
  while (r - l > 1) {
    long long md = (l + r) / 2ll;
    long long s = 0;
    for (int i = 0; i < n; ++i) s += md - mas[i];
    if (md > s)
      l = md;
    else
      r = md;
  }
  long long md = l;
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    s += md - mas[i];
  }
  if (md > s) ++l;
  cout << l << "\n";
  return 0;
}
