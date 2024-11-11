#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v) {
  os << "(";
  os << v.first << "," << v.second << ")";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  long long sz = v.size();
  for (long long i = 0; i < sz; ++i) {
    os << v[i];
    if (i != sz - 1) os << ",";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  T last = *v.rbegin();
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != last) os << ",";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v) {
  for (auto it : v) {
    os << it.first << " : " << it.second << "\n";
  }
  return os;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % 1000000007;
    }
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return res;
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long n, a[100006];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (__typeof(1) i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (long long i = n; i >= 3; --i) {
    if (a[i - 1] + a[i - 2] >= a[i]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
