#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 1;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], b[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int i = 0; i < n; i++) cin >> b[i];
    bool flag = 0;
    vector<long long int> v, value;
    for (long long int i = 0; i < n; i++)
      if (b[i] == 0) v.push_back(i), value.push_back(a[i]);
    sort(value.rbegin(), value.rend());
    for (long long int i = 0; i < v.size(); i++) a[v[i]] = value[i];
    long long int sum = 0, ans = 0;
    for (long long int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
  }
  return 0;
}
