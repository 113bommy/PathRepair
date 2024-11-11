#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
const int mod = 1e9 + 7;
int x[N], y[N];
int main() {
  int n;
  cin >> n;
  map<int, int> X, Y, VX, VY;
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    X[x[i]]++;
    Y[y[i]]++;
    cnt[{x[i], y[i]}]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (X[x[i]] - 1 + Y[y[i]] - 1) - (cnt[{x[i], y[i]}] - 1);
  }
  cout << ans / 2 << endl;
  return 0;
}
