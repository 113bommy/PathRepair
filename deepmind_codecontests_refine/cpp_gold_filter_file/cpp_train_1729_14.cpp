#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long base = 37;
long long large = 1000000000000000000LL;
int main() {
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<long long> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) k += a[i];
  long long sum = 0LL;
  for (int i = 0; i < n; i++) sum += a[i];
  long long ans = k / sum;
  vector<pair<long long, pair<long long, long long> > > eve;
  for (int i = 0; i < n; i++) {
    vector<long long> b;
    for (long long j = 1;; j++) {
      b.push_back(j);
      long long t = (a[i] - 1) / j + 1;
      if (t > j) {
        b.push_back(t);
      } else {
        break;
      }
    }
    sort(b.begin(), b.end());
    for (int j = 1; j < (int)b.size(); j++) {
      eve.push_back(pair<long long, pair<long long, long long> >(
          b[j], pair<long long, long long>(a[i], b[j - 1])));
    }
  }
  sort(eve.begin(), eve.end());
  for (int i = 0; i < (int)eve.size(); i++) {
    long long d = eve[i].first;
    long long pre = eve[i].second.second;
    long long val = eve[i].second.first;
    sum -= (val - 1) / pre + 1;
    sum += (val - 1) / d + 1;
    if (i + 1 >= (int)eve.size() || eve[i + 1].first > d) {
      if (sum * d <= k) {
        ans = max(ans, k / sum);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
