#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  int x;
  cin >> x;
  int max1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second <= x) {
      max1 = i;
    }
  }
  cout << n - max1;
  return 0;
}
