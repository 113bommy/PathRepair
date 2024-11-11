#include <bits/stdc++.h>
int IntMaxVal = (int)1e20;
int IntMinVal = (int)-1e20;
long long LongMaxVal = (long long)1e20;
long long LongMinVal = (long long)-1e20;
using namespace std;
template <typename T>
struct argument_type;
template <typename T, typename U>
struct argument_type<T(U)> {};
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& s) {
  is >> s.first >> s.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  os << '\n';
  ;
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2>& t) {
  s << t.first << ' ' << t.second;
  return s;
}
template <typename T>
vector<T> readVector(int n) {
  vector<T> res(n);
  for (int i = 0; i < n; i++) cin >> res[i];
  return res;
}
vector<pair<int, int> > points;
int n;
vector<int> parent;
vector<int> size;
vector<int> mapping;
vector<vector<int> > edges;
void solve(vector<int>& vertices, int root) {
  if (vertices.size() != size[root]) {
    cout << "Ooops";
    exit(0);
  }
  int v = vertices.front();
  for (auto v2 : vertices)
    if (points[v2] < points[v]) v = v2;
  for (int i = 0; i < vertices.size(); ++i) {
    if (vertices[i] == v) {
      vertices[i] = vertices.back();
      vertices.pop_back();
    }
  }
  mapping[root] = v + 1;
  if (!vertices.size()) return;
  int y0 = points[v].second;
  int x0 = points[v].first;
  vector<pair<double, int> > v2;
  for (auto vi : vertices)
    v2.push_back(
        make_pair(atan2(points[vi].second - y0, points[vi].first - x0), vi));
  sort(v2.begin(), v2.end());
  int p = 0;
  for (auto dest : edges[root])
    if (parent[root] != dest) {
      vector<int> nextPoints;
      while (nextPoints.size() < size[dest])
        nextPoints.push_back(v2[p++].second);
      solve(nextPoints, dest);
    }
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  parent.resize(n);
  edges.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a;
    cin >> a;
    ;
    int b;
    cin >> b;
    ;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  vector<int> q;
  q.push_back(0);
  mapping.resize(n);
  parent[q[0]] = -1;
  for (int i = 0; i < n; ++i) {
    int v = q[i];
    for (auto e : edges[v])
      if (e != parent[v]) {
        parent[e] = v;
        q.push_back(e);
      }
  }
  points = readVector<pair<int, int> >(n);
  size.assign(n, 1);
  for (int i = n - 1; i >= 0; --i) {
    int v = q[i];
    if (parent[v] != -1) size[parent[v]] += size[v];
  }
  vector<int> vertices(n);
  for (int i = 0; i < n; ++i) vertices[i] = i;
  solve(vertices, q[0]);
  cout << mapping;
}
