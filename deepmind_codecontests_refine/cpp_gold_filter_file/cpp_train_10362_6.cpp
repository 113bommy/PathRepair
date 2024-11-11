#include <bits/stdc++.h>
using namespace std;
long long const MAXN = 3e5 + 8;
long long const INF = 1e12 + 8;
long long const delta = 1000000007;
vector<long long> temp;
set<long long> pos;
set<pair<long long, long long> > st;
void dfs(long long v) {
  pos.erase(v);
  set<long long>::iterator i = pos.begin();
  temp.push_back(v);
  ;
  while (1) {
    if (!pos.size()) break;
    long long u = *i;
    if (!st.count(make_pair(u, v))) {
      dfs(u);
      if (!pos.size()) break;
      i = pos.begin();
    } else {
      i++;
      if (i == pos.end()) break;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long f, s;
  long long t = 0;
  for (long long i = 0; i < m; i++) {
    cin >> f >> s;
    if (f == 1) t++;
    if (s == 1) t++;
    st.insert(make_pair(f, s));
    st.insert(make_pair(s, f));
  }
  if (n - t - 1 < k) return cout << "impossible", 0;
  for (long long i = 2; i <= n; i++) pos.insert(i);
  long long cnt = 0;
  while (pos.size()) {
    long long v = *pos.begin();
    temp.clear();
    dfs(v);
    long long p = 0;
    for (long long i = 0; i < temp.size(); i++) {
      if (!st.count(make_pair(1, temp[i]))) p = 1;
    }
    if (!p) return cout << "impossible", 0;
    cnt++;
  }
  if (cnt > k) return cout << "impossible", 0;
  cout << "possible";
  return 0;
}
