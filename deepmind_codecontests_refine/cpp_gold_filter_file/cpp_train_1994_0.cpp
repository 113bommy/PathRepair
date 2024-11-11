#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, i, j, n, max, min, mid;
  cin >> n;
  vector<int> x(n);
  set<int> h;
  for (i = 0; i < n; i++) {
    cin >> x[i];
    h.insert(x[i]);
  }
  max = *max_element(x.begin(), x.end());
  min = *min_element(x.begin(), x.end());
  mid = (max + min) / 2;
  if (h.size() > 3) {
    d = -1;
  } else if (h.size() == 3) {
    if (h.count(mid) == 1) {
      if ((max + min) % 2 == 0) {
        d = max - mid;
      } else
        d = -1;
    } else
      d = -1;
  } else if (h.size() == 2) {
    int f = max - min;
    if (f % 2 != 0) {
      d = max - min;
    } else
      d = f / 2;
  } else if (h.size() == 1) {
    d = 0;
  }
  cout << d;
}
