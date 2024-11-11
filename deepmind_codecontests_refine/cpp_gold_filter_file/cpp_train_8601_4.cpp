#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<T> &v) {
  for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<pair<T, T> > &v) {
  for (size_t i = 0; i < v.size(); ++i)
    out << "(" << v[i].first << ", " << v[i].second << ") ";
  out << "\n";
  return out;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<vector<T> > &v) {
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = 0; j < v[i].size(); ++j) {
      out << v[i][j] << " ";
    }
    out << "\n";
  }
  return out;
}
long long get_decimal(const string &s) {
  long long f = 1;
  long long n = 0;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    n += (s[i] - '0') * f;
    f *= 10;
  }
  return n;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int k, p;
  cin >> k >> p;
  long long sum = 0;
  for (int i = 1; i <= k; ++i) {
    string s = to_string(i);
    string rev = s;
    reverse(rev.begin(), rev.end());
    sum += get_decimal(s + rev);
  }
  cout << sum % p << "\n";
  return 0;
}
