#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1e9;
const long long MOD = 1000000007;
bool sortbysecdesc(const pair<long long, long long> &a,
                   const pair<long long, long long> &b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second > b.second;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, d;
  cin >> n >> m >> d;
  vector<pair<long long, long long>> ve1, ve2;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    ve1.push_back(make_pair(x, y));
  }
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    ve2.push_back(make_pair(x, y));
  }
  sort(ve1.begin(), ve1.end(), sortbysecdesc);
  sort(ve2.begin(), ve2.end(), sortbysecdesc);
  set<pair<long long, long long>> st;
  int w = 0, s = 0;
  for (int i = m - 1; i >= 0; i--) {
    w += ve2[i].second, s += ve2[i].first;
    st.insert(make_pair(w, s));
  }
  s = 0, w = 0;
  long long mm = 0;
  for (int i = n - 1; i >= 0; i--) {
    s += ve1[i].first;
    w += ve1[i].second;
    if (d <= w) break;
    auto it = st.upper_bound(make_pair(d - w, 1e15));
    if (it == st.begin()) break;
    it--;
    mm = max(mm, s + (*it).second);
  }
  cout << mm;
}
