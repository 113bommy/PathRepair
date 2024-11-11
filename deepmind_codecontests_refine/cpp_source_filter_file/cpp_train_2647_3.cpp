#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<bool> h(100), v(100);
  int ax, ay;
  for (long long i = 0; i < n; i++) {
    cin >> ax >> ay;
    h[ax] = true;
    v[ay] = true;
  }
  long long hh = accumulate(h.begin(), h.end(), 0);
  long long vv = accumulate(v.begin(), v.end(), 0);
  cout << min(hh, vv);
  return 0;
}
