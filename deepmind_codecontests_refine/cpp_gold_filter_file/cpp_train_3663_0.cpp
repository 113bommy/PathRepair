#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0;
  cin >> n;
  int a[n];
  vector<pair<int, int>> v;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  for (i = n - 1; i >= 0; i--) {
    c += (v[i].first * (n - 1 - i) + 1);
  }
  cout << c << endl;
  for (i = n - 1; i >= 0; i--) {
    cout << v[i].second + 1 << " ";
  }
}
