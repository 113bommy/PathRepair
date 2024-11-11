#include <bits/stdc++.h>
using namespace std;
bool mmrj(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second > b.second);
}
signed main() {
  long long n, m, k, r = 1;
  cin >> n >> m >> k;
  vector<long long> v[m + 1];
  set<long long> st;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
    st.insert(a[i]);
  }
  auto it = st.begin();
  while (it != st.end()) {
    long long p = *it, i = 0, j = 1;
    long long k1 = v[p][j] - v[p][i] - 1;
    while (j < v[p].size()) {
      while (k1 > k) {
        if (i == j) {
          k1 = 0;
          break;
        }
        k1 -= (v[p][i + 1] - v[p][i]);
        i++;
      }
      r = max(r, j - i + 1);
      j++;
      k1 += (v[p][j] - v[p][j - 1] - 1);
    }
    r = max(r, j - i);
    it++;
  }
  cout << r;
}
