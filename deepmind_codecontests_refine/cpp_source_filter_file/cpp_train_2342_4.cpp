#include <bits/stdc++.h>
using namespace std;
int n, mn = 1e9, mx = -1e9;
vector<int> v;
int main() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      mx = v[n - 1] - v[0];
      mn = v[1] - v[0];
      cout << mn << " " << mx << endl;
    } else if (i == n - 1) {
      mn = v[n - 1] - v[n - 2];
      mx = v[n - 1] - v[0];
      cout << mn << " " << mx << endl;
    } else {
      mn = min((v[i + 1] - v[i]), (v[i] - v[i - 1]));
      mx = max((v[n - 1] - v[i]), (v[0] - v[i]));
      cout << mn << " " << mx << endl;
    }
  }
  return 0;
}
