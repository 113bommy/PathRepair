#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ll;
typedef vector<long long> vl;
typedef vector<ll> vll;
typedef vector<vl> vvl;
template <typename T>
ostream &operator<<(ostream &o, vector<T> v) {
  if (v.size() > 0) o << v[0];
  for (unsigned i = 1; i < v.size(); i++) o << " " << v[i];
  return o << "\n";
}
template <typename U, typename V>
ostream &operator<<(ostream &o, pair<U, V> p) {
  return o << "(" << p.first << ", " << p.second << ") ";
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (unsigned i = 0; i < v.size(); i++) in >> v[i];
  return in;
}
template <typename T>
istream &operator>>(istream &in, pair<T, T> &p) {
  in >> p.first;
  in >> p.second;
  return in;
}
vvl g(111000);
vl ind(111000, 0), vis(111000, false);
long long c = 0;
bool rec(long long node, long long p) {
  vl ch;
  ind[node] = c++;
  vis[node] = 1;
  for (auto &it : g[node]) {
    if (it == p) continue;
    if (!vis[it]) {
      if (!rec(it, node)) ch.push_back((it));
    } else if (ind[node] < ind[it])
      ch.push_back((it));
  }
  for (long long i = 0; i + 1 < ch.size(); i += 2)
    cout << ch[i] << " " << node << " " << ch[i + 1] << "\n";
  if (ch.size() % 2 == 1) {
    cout << p << " " << node << " " << ch[ch.size() - 1] << "\n";
    return true;
  }
  return false;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (m % 2 == 1) {
    cout << "No Solution"
         << "\n";
    return 0;
  }
  while (m--) {
    long long x, y;
    cin >> x >> y;
    g[x].push_back((y));
    g[y].push_back((x));
  }
  rec(1, -1);
  return 0;
}
