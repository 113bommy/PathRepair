#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  vector<long long> v(b);
  map<long long, long long> m1;
  for (long long i = 0; i < b; i++) {
    cin >> v[i];
    m1[v[i]] = i;
  }
  vector<long long> v1(c);
  vector<pair<long long, long long> > v2;
  map<long long, long long> m, m3;
  for (long long i = 0; i < c; i++) cin >> v1[i];
  for (long long i = 0; i < b; i++) {
    for (long long j = 0; j < c; j++)
      if (m3[v[i]] == 0 && v1[j] % v[i] == 0) {
        m[v[i]]++;
      }
    m3[v[i]] = 1;
    v2.push_back({m[v[i]], v[i]});
  }
  sort((v2).begin(), (v2).end());
  long long county = 1;
  for (long long i = 0; i < v2.size(); i++) {
    if (v2[i].first == v2[i + 1].first)
      county++;
    else
      break;
  }
  cout << county << '\n';
  set<int> s;
  for (long long i = 0; i < v2.size(); i++)
    for (long long j = 0; j < b; j++)
      if (v2[0].first == v2[i].first && v[j] == v2[i].second) s.insert(j + 1);
  for (auto i : s) cout << i << " ";
  return 0;
}
