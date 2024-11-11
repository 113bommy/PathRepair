#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000], b[200000];
vector<int> v;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) {
    v.push_back(a[i] - b[i]);
  }
  sort(v.begin(), v.end());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += n - (upper_bound(v.begin(), v.end(), b[i] - a[i]) - v.begin());
    if (a[i] > b[i]) res--;
  }
  cout << res / 2 << "\n";
}
