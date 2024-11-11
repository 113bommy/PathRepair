#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> b(m);
  long long count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    count += a[i] * m;
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (b[0] < a[n - 1])
    cout << -1;
  else {
    if (b[0] > a[n - 1]) count += b[0] - a[n - 2];
    for (int i = 1; i < m; ++i) {
      count += b[i] - a[n - 1];
    }
    cout << count;
  }
}
