#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  unsigned long long int idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ", ";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unsigned long long int t;
  t = 1;
  unsigned long long int n;
  unsigned long long int bits = 23;
  const unsigned long long int N = (1 << bits) - 1;
  while (t--) {
    cin >> n;
    vector<unsigned long long int> v(N);
    vector<unsigned long long int> a(n);
    unsigned long long int x;
    for (unsigned long long int i = 0; i < n; i++) {
      cin >> a[i];
      v[a[i]] = a[i];
    }
    vector<unsigned long long int> F(N);
    for (unsigned long long int i = 0; i < N; i++) {
      F[i] = v[i];
    }
    for (unsigned long long int mask = 0; mask < N; mask++) {
      for (unsigned long long int i = 0; i < bits; i++) {
        if (mask & (1 << i) && !F[mask]) F[mask] = F[mask ^ (1 << i)];
      }
    }
    unsigned long long int ans = 0;
    for (unsigned long long int i = 0; i < n; i++) {
      x = a[i];
      if (F[~x & N] != 0)
        cout << F[~x & N] << " ";
      else
        cout << -1 << " ";
    }
    cout << endl;
  }
  return 0;
}
