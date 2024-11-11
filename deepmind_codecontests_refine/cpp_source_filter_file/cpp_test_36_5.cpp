#include <bits/stdc++.h>
using namespace std;
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
const double PI = acos(-1.0);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const int mx = 1e5 + 123;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TC, C = 1;
  cin >> TC;
read:
  while (TC--) {
    int n;
    cin >> n;
    vector<int> a, b;
    map<int, int> idx;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x & 1)
        a.push_back(x);
      else
        b.push_back(x);
      idx[x] = i + 1;
      sum += (1LL * x);
    }
    if (isPrime(sum) == false) {
      cout << n << '\n';
      for (auto i : a) cout << idx[i] << " ";
      for (auto i : b) cout << idx[i] << " ";
      cout << '\n';
    } else {
      sort(a.begin(), a.end());
      sum -= a[0];
      cout << n - 1 << '\n';
      for (auto i : b) cout << idx[i] << " ";
      int l = a.size();
      for (int i = 1; i < l; i++) cout << idx[i] << " ";
      cout << '\n';
    }
  }
}
