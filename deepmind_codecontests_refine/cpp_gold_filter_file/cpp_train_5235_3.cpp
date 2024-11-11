#include <bits/stdc++.h>
using namespace std;
long long cnt, res, b[(long long)(2e5 + 7)], t, m, k, ans,
    mx = -(int)(1e9 + 7), mn = (int)(1e9 + 7), p, n, eff, thr, five, sev;
string s;
vector<int> v;
int main() {
  cin >> t;
  for (int kk = 1; kk <= t; ++kk) {
    cin >> n >> k;
    long long a[(long long)(2e5 + 7)];
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = n - k; i < n; ++i) {
      a[n] += a[i];
    }
    cout << a[n] << "\n";
  }
}
