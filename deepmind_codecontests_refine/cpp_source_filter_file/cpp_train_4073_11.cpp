#include <bits/stdc++.h>
using namespace std;
bool check(int otv, int m, int k, vector<int> a) {
  int s = 0, n = 0;
  vector<int> b;
  b = a;
  b.push_back(0);
  for (int i = a.size() - otv; i < a.size(); ++i) {
    s += a[i];
    if (s + a[i + 1] > k) {
      s = 0;
      n++;
    }
  }
  return (n < m);
}
int main() {
  int n, m, k, s = 0, otv = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int l = 1;
  int r = a.size();
  if (check(r, m, k, a)) {
    cout << r;
    return 0;
  }
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid, m, k, a))
      l = mid;
    else
      r = mid;
  }
  cout << l;
  return 0;
}
