#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxN = 1e5 + 5;
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
clock_t tStart = clock();
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (i == j || i == j + 1 || i == j - 1)
          cout << 1;
        else
          cout << 0;
      }
    }
    cout << '\n';
  }
}
