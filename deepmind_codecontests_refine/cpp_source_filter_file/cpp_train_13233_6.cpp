#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long summ = 0;
    for (long long i = 0; i < n; i++) summ += a[i];
    long long maxx = a[0], smax = a[0];
    for (long long i = 1; i < n; i++) {
      if (a[i] >= maxx) {
        smax = maxx;
        maxx = a[i];
      } else if (a[i] >= smax) {
        smax = a[i];
      }
    }
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
      if (a[i] != maxx) {
        if (summ - a[i] == 2 * maxx) ans.push_back(i);
      } else {
        if (summ - a[i] == 2 * smax) ans.push_back(i);
      }
    }
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
    cout << endl;
  }
  return 0;
}
