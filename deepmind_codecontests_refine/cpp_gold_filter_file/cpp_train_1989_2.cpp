#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k;
  cin >> n >> k;
  int h = k;
  vector<int> v(n);
  int ma = 0;
  int mi = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    ma = max(ma, v[i]);
    mi = min(mi, v[i]);
  }
  sort(v.begin(), v.end());
  int m = ma - mi;
  for (int i = 0; i < n; i++) {
    k = k - (ma - v[i]);
  }
  if (k <= 0)
    cout << ma << " " << ma + h;
  else
    cout << ma + ceil(k / (n * 1.0)) << " " << ma + h;
}
