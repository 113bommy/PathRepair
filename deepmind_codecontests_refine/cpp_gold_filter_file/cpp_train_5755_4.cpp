#include <bits/stdc++.h>
using namespace std;
void print() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> y[i];
  sort(x.begin(), x.end());
  vector<int> l(n), r(n);
  int j = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    while (x[j] - x[i] > k) --j;
    r[i] = j - i + 1;
    if (i + 1 < n) r[i] = max(r[i], r[i + 1]);
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    while (x[i] - x[j] > k) ++j;
    l[i] = i - j + 1;
    if (i > 0) l[i] = max(l[i], l[i - 1]);
  }
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, l[i] + r[i + 1]);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    print();
  }
}
