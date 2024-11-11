#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, t, m1, m2;
  cin >> t;
  while (t--) {
    long long ma = 0;
    long long ans = 0;
    cin >> n;
    long long ar[n];
    set<long long> s;
    map<long long, long long> mp;
    map<long long, long long>::iterator it;
    for (i = 0; i < n; i++) {
      cin >> ar[i];
      s.insert(ar[i]);
      mp[ar[i]]++;
    }
    e = s.size();
    for (it = mp.begin(); it != mp.end(); it++) {
      j = it->second;
      m1 = min(e, j - 1);
      m2 = min(j, e - 1);
      m = max(m1, m2);
      ans = max(ans, m);
    }
    cout << ans << endl;
  }
}
