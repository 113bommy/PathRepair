#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> v(n);
    vector<long long> w(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i] >> w[i];
      if (i != 0) {
        if ((v[i] - w[i - 1]) > 0)
          a[i] = v[i] - w[i - 1];
        else
          a[i] = 0;
        sum += a[i];
      }
    }
    if ((v[0] - w[n - 1]) > 0)
      a[0] = v[0] - w[n - 1];
    else
      a[0] = 0;
    sum += a[0];
    long long min = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if ((sum - a[i] + v[i]) < min) min = sum - a[i] + v[i];
    }
    cout << min << endl;
  }
}
