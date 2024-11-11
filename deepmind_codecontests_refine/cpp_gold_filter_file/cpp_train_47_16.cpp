#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n, x, h, a, b, max = 1;
  vector<long int> xs;
  vector<long int> hs;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> h;
    xs.push_back(x);
    hs.push_back(h);
  }
  xs.push_back(2000000005);
  a = xs[0] - hs[0];
  b = xs[0];
  for (int i = 1; i < n; i++) {
    if ((b < xs[i] - hs[i]) && (xs[i - 1] < xs[i] - hs[i])) {
      a = xs[i] - hs[i];
      b = xs[i];
      max++;
    } else {
      if (xs[i] + hs[i] < xs[i + 1]) {
        a = xs[i];
        b = xs[i] + hs[i];
        max++;
      }
    }
  }
  cout << max << '\n';
  return 0;
}
