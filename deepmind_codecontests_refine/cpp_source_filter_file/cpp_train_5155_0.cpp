#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  vector<long long> ar(n);
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
  }
  long long nmin = 3e9 + 1;
  for (long long i = 0; i < n; i++) {
    nmin = min(nmin, ar[i]);
  }
  vector<long long> pos;
  for (long long i = 0; i < n; i++) {
    if (ar[i] == nmin) pos.push_back(i);
  }
  long long st;
  if (pos.size() == 1) {
    st = (pos[0] + 1) % n + 1;
    cout << n * nmin + n - 1;
    return 0;
  }
  pair<long long, long long> ans = {-3 * 1e9, 0};
  for (long long i = 0; i < pos.size() - 1; i++) {
    if (abs(pos[i + 1] - pos[i]) > ans.first) {
      ans = make_pair(abs(pos[i + 1] - pos[i]), i);
    }
  }
  ans.first = max(ans.first, pos[0] + n - pos.back() - 1);
  st = (ans.second + 1) % n + 1;
  long long anss = n * nmin;
  anss += (ans.first);
  cout << anss - 1;
  return 0;
}
