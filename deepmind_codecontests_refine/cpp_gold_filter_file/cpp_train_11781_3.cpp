#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long mod = 1e9 + 7;
long long n, m;
vector<long long> divi;
pair<long long, long long> a[200005];
vector<long long> nod[200005];
vector<long long> nod1[200005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i].first >> a[i].second;
    nod[a[i].first].push_back(a[i].second);
    nod[a[i].second].push_back(a[i].first);
  }
  for (long long i = 1; i <= n; i++) sort((nod[i]).begin(), (nod[i]).end());
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i != n) divi.push_back(i);
      if (n / i != n) divi.push_back(n / i);
    }
  }
  for (long long i = 0; i < divi.size(); i++) {
    for (long long j = 1; j <= n; j++) nod1[j].clear();
    for (long long j = 1; j <= m; j++) {
      long long x1 = (a[j].first + divi[i]) % n;
      if (x1 == 0) x1 = n;
      long long y1 = (a[j].second + divi[i]) % n;
      if (y1 == 0) y1 = n;
      nod1[x1].push_back(y1);
      nod1[y1].push_back(x1);
    }
    bool c = true;
    long long cnt = 0;
    for (long long j = 1; j <= n; j++) sort((nod1[j]).begin(), (nod1[j]).end());
    for (long long j = 1; j <= n; j++) {
      if (nod[j] != nod1[j]) {
        cnt++;
        c = false;
      }
    }
    if (c == true) return cout << "Yes", 0;
  }
  return cout << "No", 0;
}
