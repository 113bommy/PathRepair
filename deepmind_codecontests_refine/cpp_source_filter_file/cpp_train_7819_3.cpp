#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, zp, m;
  long long num;
  cin >> n;
  vector<pair<int, long long> > a(n, pair<int, long long>(0, 0));
  for (int i = 0; i < n; ++i) {
    cin >> num;
    a[i].second = num;
    m = 0;
    for (int j = 0; j < num; ++j) {
      cin >> zp;
      m = max(m, zp);
    }
    a[i].first = m;
  }
  sort(a.begin(), a.end());
  int count = 0, delta;
  for (int i = 0; i < n - 1; ++i) {
    delta = a[i + 1].first - a[i].first;
    count += delta * a[i].second;
    a[i + 1].second += a[i].second;
  }
  cout << count << endl;
  return 0;
}
