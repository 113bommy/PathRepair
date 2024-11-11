#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string s;
  cin >> s;
  long long a[26];
  memset(a, 0, sizeof(a));
  vector<pair<char, long long> > v;
  for (long long i = 0; i < s.length(); i++) {
    a[(long long)(s[i] - 'a')]++;
    v.push_back({s[i], i});
  }
  long long ans = 0;
  for (long long i = 0; i < 26; i++) {
    if (a[i] > 0) ans++;
  }
  sort(v.begin(), v.end());
  long long size = 0;
  vector<pair<long long, char> > v1;
  for (long long i = v.size() - 1; i >= 0; i--) {
    v1.push_back({v[i].second, v[i].first});
  }
  long long i = 0, j = 0;
  long long k;
  while (ans--) {
    size = 0;
    k = j;
    for (i = j; i < v1.size() - 1; i++, j++) {
      if (v1[i].second != v1[i + 1].second) break;
      size++;
    }
    sort(v1.begin() + k, v1.begin() + k + size + 1);
    j = i;
    j += 1;
  }
  k = 0;
  long long f = 0;
  string q = "";
  for (long long i = 0; i < v1.size() - 1; i++) {
    if (v1[i].first >= f) q += v1[i].second;
    if (v1[i].second != v1[i + 1].second) {
      f = max(f, v1[i].first);
    }
  }
  if (v1[v1.size() - 1].first >= f) q += v1[v1.size() - 1].second;
  cout << q;
}
