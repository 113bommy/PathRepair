#include <bits/stdc++.h>
using namespace std;
class UF {
 public:
  vector<long long> v;
  vector<long long> size;
  long long cnt = 0;
  UF(long long n) {
    v = vector<long long>(n);
    size = vector<long long>(n, 1);
    for (long long i = 0; i < n; i++) v[i] = i;
    cnt = n;
  }
  long long find(long long i) {
    while (i != v[i]) i = v[i];
    return i;
  }
  bool same(long long i, long long j) {
    i = find(i);
    j = find(j);
    return i == j;
  }
  void unite(long long i, long long j) {
    i = find(i);
    j = find(j);
    if (i == j) return;
    if (size[i] > size[j]) swap(i, j);
    size[j] += size[i];
    v[i] = j;
    cnt--;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, p, q;
  cin >> n >> m >> p >> q;
  vector<vector<long long>> edges(m, vector<long long>(3));
  for (long long i = 0; i < m; i++)
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  UF uf(n + 1);
  for (long long i = 0; i < m; i++) {
    uf.unite(edges[i][0], edges[i][1]);
  }
  unordered_map<long long, long long> mp, nodeInGroup;
  for (long long i = 0; i < m; i++) {
    long long id = uf.find(edges[i][0]);
    mp[id] += edges[i][2];
    nodeInGroup[id] = edges[i][0];
  }
  for (long long i = 1; i <= n; i++) {
    if (uf.size[uf.find(i)] == 1) {
      mp[uf.find(i)] = 0;
      nodeInGroup[uf.find(i)] = i;
    }
  }
  if (uf.cnt - 1 - q > p || uf.cnt - 1 < q) {
    cout << "NO" << endl;
    return 0;
  }
  multiset<pair<long long, long long>> st;
  for (auto& [key, val] : mp) st.insert({val, key});
  vector<pair<long long, long long>> ret;
  long long sz = uf.cnt;
  for (long long i = 0; i < sz - 1 - q; i++) {
    auto it1 = st.begin();
    auto it2 = next(it1);
    long long ia = it1->second, ib = it2->second;
    long long a = it1->first, b = it2->first;
    st.erase(it1);
    st.erase(it2);
    long long val = a + b + 1 + a + b;
    val = min(val, (long long)(1e9));
    st.insert({val, ia});
    ret.push_back({nodeInGroup[ia], nodeInGroup[ib]});
    uf.unite(ia, ib);
  }
  long long left = p - (sz - 1 - q);
  if (left == 0) {
    cout << "YES" << endl;
    for (auto& [a, b] : ret) {
      cout << a << " " << b << endl;
    }
    return 0;
  }
  long long idx = -1;
  for (long long i = 1; i <= n; i++) {
    if (uf.size[uf.find(i)] > 1) {
      idx = nodeInGroup[uf.find(i)];
      break;
    }
  }
  if (idx == -1) {
    cout << "NO" << endl;
    return 0;
  }
  long long idx2;
  for (long long i = 1; i <= n; i++) {
    if (uf.find(i) == uf.find(idx) && i != idx) {
      idx2 = i;
      break;
    }
  }
  for (long long i = 0; i < left; i++) ret.push_back({idx, idx2});
  cout << "YES" << endl;
  for (auto& [a, b] : ret) {
    cout << a << " " << b << endl;
  }
  return 0;
}
