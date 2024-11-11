#include <bits/stdc++.h>
using namespace std;
long long a[400010];
long long b[200010];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  vector<long long> v1[30], v2[30];
  long long j = 1;
  for (char i : s1) {
    if (i == '?')
      v1[26].push_back(j);
    else
      v1[i - 'a'].push_back(j);
    j++;
  }
  j = 1;
  for (char i : s2) {
    if (i == '?')
      v2[26].push_back(j);
    else
      v2[i - 'a'].push_back(j);
    j++;
  }
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < 26; i++) {
    while (!v1[i].empty() && !v2[i].empty())
      v.push_back({v1[i].back(), v2[i].back()}), v1[i].pop_back(),
          v2[i].pop_back();
    while (!v1[i].empty() && !v2[26].empty())
      v.push_back({v1[i].back(), v2[26].back()}), v1[i].pop_back(),
          v2[26].pop_back();
    while (!v1[26].empty() && !v2[i].empty())
      v.push_back({v1[26].back(), v2[i].back()}), v1[26].pop_back(),
          v2[i].pop_back();
  }
  cout << v.size() << endl;
  for (auto i : v) cout << i.first << " " << i.second << endl;
  return 0;
}
