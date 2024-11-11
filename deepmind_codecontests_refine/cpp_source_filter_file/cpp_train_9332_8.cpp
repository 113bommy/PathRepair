#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a1(n);
  for (int i = 0; i < n; ++i) {
    cin >> a1[i];
  }
  vector<long long> a2(m);
  for (int i = 0; i < m; ++i) {
    cin >> a2[i];
  }
  long long res = LLONG_MAX;
  for (int k = 0; k < n; ++k) {
    long long curMax = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i != k) {
          curMax = max(curMax, a1[i] * a2[j]);
        }
      }
    }
    res = min(res, curMax);
  }
  cout << res << endl;
  return 0;
}
