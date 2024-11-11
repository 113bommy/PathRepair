#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T> v) {
  os << "(" << v.first << ", " << v.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i > 0) {
      os << " ";
    }
    os << v[i];
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<vector<T>> v) {
  for (int i = 0; i < (int)v.size(); i++) {
    if (i > 0) {
      os << endl;
    }
    os << v[i];
  }
  return os;
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
string num2bit(long long num, long long len) {
  string bit = "";
  for (int i = 0; i < (int)len; ++i) {
    bit += char('0' + (num >> i & 1));
  }
  return bit;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(n), b(m);
  for (int i = 0; i < (int)n; ++i) cin >> a[i];
  for (int i = 0; i < (int)m; ++i) cin >> b[i];
  long long idx = -1, jdx = -1;
  for (int i = 0; i < (int)n; ++i) {
    if (a[i] % p != 0) {
      idx = i;
      break;
    }
  }
  for (int i = 0; i < (int)m; ++i) {
    if (b[i] % p != 0) {
      jdx = i;
      break;
    }
  }
  cout << idx + jdx << endl;
  return 0;
}
