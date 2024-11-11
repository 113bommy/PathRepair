#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int main() {
  int n;
  long long h;
  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    v.push_back(a[i]);
    sort(v.rbegin(), v.rend());
    long long mx = 0;
    for (int j = 0; j < v.size(); j += 2) {
      if (j == v.size() - 1) {
        mx += v[j];
      } else {
        mx += v[j + 1];
      }
    }
    if (mx <= h) ans = i;
  }
  cout << ans;
}
