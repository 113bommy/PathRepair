#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n;
  cin >> h >> n;
  vector<long long> ar;
  long long cur = 0;
  long long mn = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cur += x;
    ar.push_back(cur);
    mn = min(mn, cur);
  }
  long long t = ar[n - 1];
  long long ans = 0;
  if (mn <= -h) {
  } else if (t >= 0) {
    cout << "-1\n";
    return 0;
  } else {
    ans += (h + mn + -t - 1) / -t * n;
    h += (h + mn + -t - 1) / -t * t;
  }
  if (h > 0)
    for (int i = 0; i < n; ++i) {
      ++ans;
      if (ar[i] <= -h) break;
    }
  cout << ans << "\n";
}
