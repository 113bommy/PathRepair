#include <bits/stdc++.h>
using namespace std;
int n, m, ma = -9999, l = 0, r = 0;
vector<pair<int, int> > a;
int main() {
  int x, f = 0, s = 0, t1 = 0, t2 = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a.push_back(make_pair(x, 1));
  }
  t1 = n * 3;
  cin >> m;
  for (int j = 1; j <= m; j++) {
    cin >> x;
    a.push_back(make_pair(x, 2));
  }
  t2 = m * 3;
  sort(a.begin(), a.end());
  int q = t1, w = t2;
  if (q - w > ma) {
    ma = q - w;
    l = q;
    r = w;
  }
  for (int i = 0; i < a.size(); i++) {
    if (a[i].second == 1)
      t1--;
    else if (a[i].second == 2)
      t2--;
    q = t1;
    w = t2;
    if (q - w > ma) {
      ma = q - w;
      l = q;
      r = w;
    } else if (q - w == ma) {
      if (q > l) {
        l = q;
        r = w;
      }
    }
  }
  cout << l << ":" << r;
  return 0;
}
