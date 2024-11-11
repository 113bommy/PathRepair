#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long int n, m;
  cin >> n >> m;
  set<long long int> odd, even;
  map<long long int, int> mop, mopodd, mopeven;
  int o = 0, e = 0;
  vector<long long int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    if (vec[i] & 1)
      o++;
    else
      e++;
  }
  for (int i = 0; i < n; i++) {
    if (vec[i] & 1)
      odd.insert(vec[i]);
    else
      even.insert(vec[i]);
    if (mop[vec[i]]) vec[i] = -1;
    mop[vec[i]]++;
  }
  if (odd.size() == n / 2 && even.size() == n / 2) {
    cout << 0 << endl;
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
    return 0;
  }
  if (abs(o - e) / 2 > m) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if ((vec[i] & 1) && odd.size() > n / 2)
      odd.erase(vec[i]), vec[i] = -1;
    else if (!(vec[i] & 1) && even.size() > n / 2)
      even.erase(vec[i]), vec[i] = -1;
  }
  for (__typeof((odd).begin()) it = (odd).begin(); it != (odd).end(); it++)
    mopodd[*it]++;
  for (__typeof((even).begin()) it = (even).begin(); it != (even).end(); it++)
    mopeven[*it]++;
  int ans = 0;
  int last_odd = 0, last_even = 0, numodd = 1, numeven = 2;
  for (int i = 0; i < n; i++) {
    if (vec[i] == -1) {
      if (odd.size() < n / 2) {
        while (mopodd[numodd]) numodd += 2;
        odd.insert(numodd);
        mopodd[numodd]++;
        last_odd = numodd;
        vec[i] = numodd;
        ans++;
      } else if (even.size() < n / 2) {
        while (mopeven[numeven]) numeven += 2;
        even.insert(numeven);
        mopeven[numeven]++;
        last_even = numeven;
        vec[i] = numeven;
        ans++;
      }
    }
  }
  if (last_odd <= m && last_even <= m && odd.size() == n / 2 &&
      even.size() == n / 2) {
    cout << ans << endl;
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
