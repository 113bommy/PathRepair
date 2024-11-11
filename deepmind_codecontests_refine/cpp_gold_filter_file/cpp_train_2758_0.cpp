#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  vector<int> lf(n + 1, 0);
  vector<int> rt(n + 1, 0);
  int q = 1;
  for (int i = 0; i < n; i++) {
    q = min(v[i], q);
    lf[i] = q;
    q++;
  }
  q = 1;
  for (int i = n - 1; i >= 0; i--) {
    q = min(q, v[i]);
    rt[i] = q;
    q++;
  }
  int res = numeric_limits<int>::min();
  for (int i = 0; i < n; i++) {
    res = max(res, min(rt[i], lf[i]));
  }
  cout << res;
  return 0;
}
