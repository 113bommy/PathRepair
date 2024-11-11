#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long parent[200001], Rank[200001];
void init() {
  for (long long i = 0; i < 200001; i++) {
    Rank[i] = 0;
    parent[i] = i;
  }
}
long long find(long long a) {
  return parent[a] = (parent[a] == a) ? a : find(parent[a]);
}
void merge(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (Rank[a] == Rank[b]) {
    Rank[a]++;
  }
  if (Rank[a] > Rank[b]) {
    parent[b] = a;
  } else {
    parent[a] = b;
  }
}
void solve() {
  init();
  long long n;
  cin >> n;
  vector<string> v(n);
  map<char, vector<long long>> m;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    for (long long j = 0; j < ((int)(v[i]).size()); j++)
      m[v[i][j]].push_back(i);
  };
  for (auto& it : m) {
    for (long long i = 0; i < ((int)(it.second).size()); i++) {
      merge(it.second[i], it.second[0]);
    }
  }
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    s.insert(find(i));
  }
  cout << ((int)(s).size()) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
