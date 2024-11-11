#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int t = a[0], s = INT_MAX, ts = INT_MAX, rt;
  do {
    if (s > ts) {
      s = ts;
      rt = t;
    }
    ts = 0;
    for (int i = 0; i < n; i++) {
      if (abs(a[i] - t) > 1) {
        ts = ts + (abs(a[i] - t) - 1);
      }
    }
    t++;
  } while (t <= a[n - 1]);
  if (s > ts) {
    s = ts;
    rt = t;
  }
  cout << rt - 1 << " " << s;
}
