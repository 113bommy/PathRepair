#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
 public:
  long long int n;
  vector<pair<long long int, long long int>> parent;
  vector<long long int> rank;
  DisjointSet() {
    n = 0;
    parent = vector<pair<long long int, long long int>>(0);
    rank = vector<long long int>(0);
  }
  DisjointSet(long long int v) {
    n = v;
    parent = vector<pair<long long int, long long int>>(v + 1);
    rank = vector<long long int>(v + 1);
  }
  void makeSet(long long int v) {
    parent[v] = make_pair(v, 0);
    rank[v] = 0;
  }
  pair<long long int, long long int> find_set(long long int v) {
    if (v != parent[v].first) {
      long long int len = parent[v].second;
      parent[v] = find_set(parent[v].first);
      parent[v].second += len;
    }
    return parent[v];
  }
  void union_sets(long long int a, long long int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if (a != b) {
      if (rank[a] < rank[b]) swap(a, b);
      parent[b] = make_pair(a, 1);
      if (rank[a] == rank[b]) rank[a]++;
    }
  }
};
int main() {
  long long int n, e;
  cin >> n >> e;
  DisjointSet ds(n);
  for (long long int i = 1; i <= n; i++) {
    ds.makeSet(i);
  }
  for (long long int i = 0; i < e; i++) {
    long long int x, y;
    cin >> x >> y;
    ds.union_sets(x, y);
  }
  long long int m;
  map<long long int, long long int> tot;
  for (long long int i = 1; i <= n; i++) {
    tot[ds.find_set(i).first]++;
  }
  cin >> m;
  long long int count = -1;
  map<long long int, bool> ck;
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    long long int a = ds.find_set(x).first;
    long long int b = ds.find_set(y).first;
    if (a == b) {
      ck[a] = true;
    }
  }
  map<long long int, bool> ck1;
  for (long long int i = 1; i <= n; i++) {
    long long int a = ds.find_set(i).first;
    if (ck1[a] == false && ck[a] == false) {
      count = max(count, tot[a]);
      ck1[a] = true;
    }
  }
  cout << count << endl;
}
