#include <bits/stdc++.h>
using namespace std;
long long* parent;
long long* size;
void make_set(long long v) {
  parent[v] = v;
  size[v] = 1;
}
long long find_set(long long v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_set(long long u, long long v) {
  long long p1, p2;
  p1 = find_set(u);
  p2 = find_set(v);
  if (p1 != p2) {
    if (size[p1] < size[p2]) swap(p1, p2);
    parent[p2] = p1;
    size[p1] += size[p2];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> vc(n + 1);
  parent = new long long[n + 1];
  size = new long long[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> vc[i];
    make_set(i);
  }
  long long a, b;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b;
    union_set(a, b);
  }
  unordered_map<long long, long long> mp;
  vector<vector<long long> > ele(n + 1);
  vector<vector<long long> > ind(n + 1);
  long long k;
  long long p = 0, pp;
  for (long long i = 1; i <= n; i++) {
    k = find_set(i);
    if (mp[k] == 0) {
      p++;
      pp = p;
      mp[k] = p;
    } else {
      pp = mp[k];
    }
    ele[pp].push_back(vc[i]);
    ind[pp].push_back(i);
  }
  for (long long i = 1; i <= p; i++) {
    sort(ele[i].begin(), ele[i].end(), greater<long long>());
    sort(ind[i].begin(), ind[i].end());
    for (long long j = 0; j < ele[i].size(); j++) {
      vc[ind[i][j]] = ele[i][j];
    }
  }
  for (long long i = 1; i <= n; i++) cout << vc[i] << " ";
  return 0;
}
