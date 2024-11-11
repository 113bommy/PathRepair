#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
  int n;
  cin >> n;
  vector<long long> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];
  vector<int> res(n);
  map<int, int> mp;
  int fl = 1;
  for (int i = 0; i < n; i++) {
    int t = (i + ar[i]) % n;
    if (t < 0)
      res[i] = (t + n) % n;
    else
      res[i] = t;
    if (mp.find(res[i]) == mp.end())
      mp[t] = 1;
    else
      fl = 0;
  }
  if (fl)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
