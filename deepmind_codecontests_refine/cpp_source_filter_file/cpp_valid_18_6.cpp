#include <bits/stdc++.h>
using namespace std;
int x[105], y[105];
bool usd[205];
vector<int> v;
int main() {
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) usd[i] = false;
    int cnt = 0, num = 0;
    for (int i = 1; i <= k; ++i) {
      cin >> x[i] >> y[i], usd[x[i]] = usd[y[i]] = true;
      if (x[i] > y[i]) swap(x[i], y[i]);
    }
    for (int i = 1; i <= 2 * n; ++i) {
      if (!usd[i]) v.push_back(i);
    }
    for (int i = 0; i < n - k; ++i) {
      ++num;
      x[k + num] = v[i];
      y[k + num] = v[i + n - k];
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (x[i] < x[j] && x[j] < y[i] && y[i] < y[j]) ++cnt;
        if (x[j] < x[i] && x[i] < y[j] && y[j] < y[i]) ++cnt;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
