#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> good, bad;
  for (long long i = 0; i < n; i++) {
    long long val = sqrt(a[i]);
    if (val * val == a[i])
      good.push_back(a[i]);
    else
      bad.push_back(a[i]);
  }
  long long sz1 = good.size(), sz2 = bad.size();
  if (sz1 == sz2) {
    cout << 0 << '\n';
  } else if (sz1 > sz2) {
    long long nz = 0;
    for (auto it : good) {
      if (it) nz++;
    }
    long long req = (sz1 - sz2) / 2;
    if (nz >= req)
      cout << nz << '\n';
    else
      cout << nz + (req - nz) * 2 << '\n';
  } else {
    vector<long long> ans;
    long long req = (sz2 - sz1) / 2;
    for (auto it : bad) {
      long long val = sqrt(it);
      long long down = it - val * val, up = (val + 1) * (val + 1) - it;
      ans.push_back(min(down, up));
    }
    sort(ans.begin(), ans.end());
    long long fans = 0;
    for (long long i = 0; i < req; i++) {
      fans += ans[i];
    }
    cout << fans << '\n';
  }
}
