#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c, d, start, len;
vector<pair<long long, long long> > ar;
multiset<long long> s;
long long rat[300005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> a >> b >> c >> d >> start >> len;
  ar.resize(n + 1);
  for (long long i = 1; i <= n; i++) cin >> ar[i].first >> ar[i].second;
  long long co = start;
  rat[0] = start;
  for (long long i = 1; i <= n; i++) {
    if (ar[i].second)
      co += c;
    else
      co -= d;
    rat[i] = co;
  }
  long long j = 0;
  ar[0].first = 0;
  long long val = start;
  for (long long i = 0; i <= n; i++) {
    while (j <= n && ar[j].first < ar[i].first + 1 + len) {
      s.insert(rat[j++]);
    }
    if (ar[i].second)
      val += a;
    else
      val -= b;
    if (i == 0) val = start;
    if (val < 0) {
      cout << "-1";
      return 0;
    }
    s.erase(rat[i]);
    if (s.empty()) {
      cout << ar[i].first + 1;
      return 0;
    }
    long long mi = *(s.begin());
    mi -= rat[i];
    if (val + mi >= 0) {
      cout << ar[i].first + 1;
      return 0;
    }
  }
  cout << ar[n].first + 1;
  return 0;
}
