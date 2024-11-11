#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, k;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v1(n), v2(n);
    long long c1 = 0, c2 = 0;
    for (i = (0); i < (n); i++) {
      cin >> v1[i];
      if (v1[i] == 1)
        c1++;
      else
        c1--;
    }
    reverse((v1).begin(), (v1).end());
    for (i = (0); i < (n); i++) {
      cin >> v2[i];
      if (v2[i] == 1)
        c2++;
      else
        c2--;
    }
    map<long long, long long> m;
    long long rem = c2;
    m.insert(make_pair(0, c2));
    for (i = (0); i < (n); i++) {
      if (v2[i] == 1)
        rem--;
      else
        rem++;
      if (m.find(rem) == m.end()) {
        m.insert(make_pair(rem, i + 1));
      }
    }
    long long ans = 1000000000000000011LL;
    long long curr = c1;
    if (m.find(-curr) != m.end()) {
      ans = min(ans, m[-curr]);
    }
    for (i = (0); i < (n); i++) {
      if (v1[i] == 1)
        curr--;
      else
        curr++;
      if (m.find(-curr) != m.end()) {
        ans = min(ans, i + m[-curr] + 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
