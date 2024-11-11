#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].second;
    a[i].first = i - a[i].second + 1;
  }
  sort(a.begin(), a.end());
  int ma = 0, tma = a[0].second;
  for (int i = 0; i < n; ++i) {
    if (a[i].second > ma) ma = a[i].second;
    if (a[i].first == a[i - 1].first && i > 0) {
      if (tma == 0) tma = a[i - 1].second;
      tma += a[i].second;
    } else {
      tma = 0;
    }
    if (ma < tma) ma = tma;
  }
  cout << ma;
}
