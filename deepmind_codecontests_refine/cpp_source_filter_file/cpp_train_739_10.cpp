#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> get_subset(vector<long long>& a) {
  long long n = (long long)a.size();
  vector<vector<long long>> r;
  for (long long i = 1; i < (1 << n); i++) {
    vector<long long> sub;
    for (long long j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sub.push_back(a[j]);
      }
    }
    r.push_back(sub);
  }
  return r;
}
long long mainx() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += a[i];
  if (sum & 1) {
    cout << "NO" << endl;
    return 0;
  } else if (sum % 360 == 0)
    cout << "YES" << endl;
  else {
    long long sum = accumulate(a.begin(), a.end(), 0);
    vector<vector<long long>> sub = get_subset(a);
    for (auto x : sub) {
      long long sx = accumulate(x.begin(), x.end(), 0);
      if (abs(sum - sx) % 360 == 0) {
        cout << "YES" << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
    return 0;
  }
  return 0;
}
inline void include() {}
int32_t main() {
  include();
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  for (long long t = 1; t <= tt; t++) {
    mainx();
  }
  return 0;
}
