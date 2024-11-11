#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long n, m;
map<string, long long> mp, vis;
int main() {
  long long d, i, j, k, x, y, z, l, r, p, q;
  long long ans = 0, cn = 0, cnt = 0;
  string s[105];
  cin >> n >> m;
  long long a[n];
  set<string> st;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < m; i++)
    cin >> s[i], mp[s[i]]++, vis[s[i]] = 1, st.insert(s[i]);
  vector<long long> v;
  for (auto i : st) v.push_back(mp[i]);
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  sort(a, a + n);
  long long mn = 0, mx = 0;
  i = 0, j = 0;
  while (i < n) {
    mn += v[j] * a[i];
    cn += v[j];
    i++, j++;
    if (j == v.size()) break;
  }
  i = n - 1, j = 0, cn = 0;
  while (i >= 0) {
    mx += v[j] * a[i];
    cn += v[j];
    i--, j++;
    if (j == v.size()) break;
  }
  cout << mn << " " << mx << endl;
  return 0;
}
