#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, l, r, x, y, a, b, m, pos, k, n, temp, temp1;
  cin >> t;
  while (t--) {
    long long c1 = 0, c2 = 0, a1 = 0, a2 = 0;
    cin >> n >> k;
    vector<long long> a, b;
    for (long long i = 0; i < n; i++) {
      cin >> temp;
      a.push_back(temp);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (long long i = 1; i < a.size(); i++) {
      ans += ((k - i) / a[0]);
    }
    cout << ans << endl;
  }
}
