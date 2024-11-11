#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &out, vector<T> &v) {
  for (typename vector<T>::size_type i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n";
  return out;
}
template <typename T, typename N>
std::ostream &operator<<(std::ostream &out, vector<pair<T, N> > &v) {
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
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> left(n), a(n);
  int rating = 0, needed_to_maximize = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    rating += a[i] / 10;
    left[i] = (a[i] % 10 == 0) ? 0 : 10 - a[i] % 10;
    a[i] += left[i];
    needed_to_maximize += 100 - a[i];
  }
  sort(left.rbegin(), left.rend());
  int i = 0;
  while (i < n && k >= left[i]) {
    if (left[i]) {
      k -= left[i];
      ++rating;
    }
    ++i;
  }
  rating += min(k / 10, needed_to_maximize / 10);
  cout << rating << "\n";
  return 0;
}
