#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  boost();
  int n;
  cin >> n;
  long a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<long> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = a[i] - b[i];
  }
  sort(c.begin(), c.end());
  long count = 0;
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(c.begin() + i + 1, c.end(), -c[i]);
    int d = c.end() - it;
    count += d;
  }
  cout << count;
}
