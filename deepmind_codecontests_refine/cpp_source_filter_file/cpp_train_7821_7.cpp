#include <bits/stdc++.h>
using namespace std;
const double PI{3.1415926535897932384626433832795};
const int MOD{static_cast<int>(1e9 + 7)};
const double EPS{1e-9};
template <typename T, size_t N>
istream &operator>>(istream &is, array<T, N> &ARR) {
  for (T &a : ARR) is >> a;
  return is;
}
template <typename T, size_t N>
ostream &operator<<(ostream &os, array<T, N> &ARR) {
  for (T const &a : ARR) os << a << " ";
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &VEC) {
  for (T &v : VEC) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &VEC) {
  for (T const &v : VEC) os << v << " ";
  return os;
}
template <typename T>
istream &operator>>(istream &is, deque<T> &DEQ) {
  for (T &d : DEQ) is >> d;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &DEQ) {
  for (const T &d : DEQ) os << d << " ";
  return os;
}
template <typename T>
istream &operator>>(istream &is, list<T> &LIS) {
  for (T &l : LIS) is >> l;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const list<T> &LIS) {
  for (T const &l : LIS) os << l << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &ST) {
  for (auto const &s : ST) os << s << " ";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &U_ST) {
  for (T const &us : U_ST) os << us << " ";
  return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &PR) {
  is >> PR.first >> PR.second;
  return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &PR) {
  os << "[" << PR.first << ": " << PR.second << "]";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &MP) {
  os << "[ ";
  for (pair<T1, T2> const &m : MP) os << m << " ";
  os << "]";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const unordered_map<T1, T2> &U_MP) {
  os << "[ ";
  for (pair<T1, T2> const &um : U_MP) os << um << " ";
  os << "]";
  return os;
}
template <typename T, size_t R, size_t C>
istream &operator<<(istream &is, array<array<T, C>, R> &MAT) {
  for (array<T, C> &ROW : MAT) cin >> ROW;
  return is;
}
template <typename T, size_t R, size_t C>
ostream &operator<<(ostream &os, array<array<T, C>, R> &MAT) {
  for (array<T, C> &ROW : MAT) os << ROW << endl;
  return os;
}
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &MAT) {
  for (vector<T> &ROW : MAT) is >> ROW;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<vector<T>> &MAT) {
  for (vector<T> &ROW : MAT) os << ROW << endl;
  return os;
}
template <typename T>
int cntDigits(const T &N) {
  return (static_cast<int>(log10(N)) + 1);
}
template <typename T>
bool isPowOfTwo(const T &N) {
  return (N && (!(N & (N - 1))));
}
template <typename T>
bool dblEqual(const T &a, const T &b) {
  return abs(a - b) < EPS;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr.setf(std::ios::boolalpha);
  cout << std::fixed;
  cout << std::setprecision(6);
  int n{};
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  int last_taken{INT_MAX};
  int sum{};
  for (int i{n - 1}; i >= 0; --i) {
    if (arr.at(i) < last_taken) {
      last_taken = arr.at(i);
      sum += arr.at(i);
    } else if (arr.at(i) == last_taken) {
      last_taken = max(0, arr.at(i) - 1);
      sum += max(0, arr.at(i) - 1);
    } else if (arr.at(i) > last_taken) {
      last_taken = max(last_taken - 1, 0);
      sum += last_taken;
    }
  }
  cout << sum << endl;
  return 0;
}
