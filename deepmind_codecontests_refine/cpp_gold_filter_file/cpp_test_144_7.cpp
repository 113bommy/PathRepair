#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long calc(long long x) { return x * (x + 1) / 2; }
int mex(set<int> &st) {
  int ret = 0;
  while (st.count(ret)) ret++;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int md = n % m;
    vector<vector<bool> > a(k, vector<bool>(n + 1, false));
    int cur = 1;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n - (n % m) * (n / m + 1); j++) {
        a[i][cur] = 1;
        cur++;
        if (cur == n + 1) cur = 1;
      }
    }
    vector<int> v, v2;
    for (int i = 0; i < k; i++) {
      v.clear();
      v2.clear();
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == 0) {
          v2.push_back(j);
        } else
          v.push_back(j);
      }
      for (int i = 0; i < (int)v.size(); i += n / m) {
        cout << n / m << ' ';
        for (int j = i; j < i + n / m; j++) cout << v[j] << ' ';
        cout << '\n';
      }
      for (int i = 0; i < (int)v2.size(); i += +n / m + 1) {
        cout << n / m + 1 << ' ';
        for (int j = i; j < i + n / m + 1; j++) cout << v2[j] << ' ';
        cout << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}
