#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
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
vector<pair<long long, long long> > A, B;
bool func(long long x, long long y) {
  int idx = upper_bound(A.begin(), A.end(), make_pair(x, y)) - A.begin();
  --idx;
  if (A[idx].first <= x && A[idx].second <= y) return 1;
  idx = upper_bound(B.begin(), B.end(), make_pair(x, y)) - B.begin();
  --idx;
  if (B[idx].first <= x && B[idx].second <= y) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b;
  cin >> a >> b;
  for (long long i = 1; i * i <= a; ++i) {
    if (a % i == 0) {
      long long x = i;
      long long y = a / i;
      A.emplace_back(make_pair(x, y));
    }
  }
  for (long long i = 1; i * i <= b; ++i) {
    if (b % i == 0) {
      long long x = i;
      long long y = b / i;
      B.emplace_back(make_pair(x, y));
    }
  }
  long long sum = a + b;
  long long ans = infLL;
  for (long long i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      long long x = i;
      long long y = sum / i;
      if (!func(x, y)) continue;
      ans = min(ans, 2LL * (x + y));
    }
  }
  cout << ans;
}
