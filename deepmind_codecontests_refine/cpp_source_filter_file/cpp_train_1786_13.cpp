#include <bits/stdc++.h>
using namespace std;
long long ceil(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else {
    return (a / b) + 1;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    long long tot = (n - 2) * 3 + 4;
    long long v[n];
    map<long long, set<long long>> pos;
    for (long long i = 0; i < k; i++) {
      cin >> v[i];
      pos[v[i]].insert(i);
    }
    map<long long, long long> done;
    long long minus = 0;
    for (long long i = 0; i < k; i++) {
      if (done[v[i]] == 0) {
        done[v[i]] = 1;
      } else {
        continue;
      }
      long long temp1 = v[i] + 1;
      long long temp2 = v[i] - 1;
      if (pos.count(temp1) != 0) {
        auto it1 = pos[temp1].upper_bound(i);
        if (it1 != pos[temp1].end()) minus++;
      }
      if (pos.count(temp2) != 0) {
        auto it2 = pos[temp2].upper_bound(i);
        if (it2 != pos[temp2].end()) minus++;
      }
    }
    cout << tot - minus - pos.size() << '\n';
  }
  cin.clear();
  cin.get();
  return 0;
}
