#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996);
const long long INF = 1e17;
const long double eps = 0.00000000001;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long n = 0, x = 0, y = 0, m = 0, k = 0, l = 0, r = 0, a = 0,
                     b = 0, val = 0, flag = 0, max1 = -INF, min1 = INF, c = 0,
                     d = 0, sum = 0, index = 0;
  string s;
  cin >> n;
  vector<long long> g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  vector<long long> pref(n + 5);
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + g[i - 1];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r;
    sum = pref[r] - pref[l];
    cout << sum / 10 << endl;
  }
  return 0;
}
