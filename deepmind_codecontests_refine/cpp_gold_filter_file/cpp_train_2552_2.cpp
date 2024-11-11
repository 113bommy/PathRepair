#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i += 1) cin >> v[i];
    sort(v.begin(), v.end());
    vector<long long> vaux = v;
    for (int i = n - 2; i >= 0; --i)
      if (vaux[i] >= v[i + 1]) v[i] = v[i + 1] - 1;
    long long sum = 0;
    for (auto vi : v)
      if (vi > 0) sum += vi;
    cout << sum << "\n";
  }
  return 0;
}
