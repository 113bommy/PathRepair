#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n;
  set<long long> s;
  map<long long, long long int> mp, mp1;
  for (long long i = 1; i <= n; i++) {
    cin >> k;
    if (k <= 0) s.insert(k), mp1[k]++;
    if (k >= 0) mp[k]++;
  }
  set<long long>::iterator it = s.begin();
  long long couple = 0;
  for (; it != s.end(); it++) {
    if (*it == 0) {
      couple += (mp[*it] * (mp[*it] - 1)) / 2;
    } else if (mp[abs(*it)] > 1)
      couple += mp1[*it] * mp[abs(*it)];
  }
  cout << couple << endl;
}
