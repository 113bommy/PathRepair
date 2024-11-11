#include <bits/stdc++.h>
using namespace std;
const double PI{3.1415926535897932384626433832795};
const int MOD{static_cast<int>(1e9 + 7)};
const double EPS{1e-9};
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
template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &VEC) {
  for (vector<T> &i : VEC)
    for (T &j : i) is >> j;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &VEC) {
  for (vector<T> const &i : VEC) {
    for (T const &j : i) os << j << " ";
    os << endl;
  }
  return os;
}
template <typename T>
void vvtrNS(const vector<vector<T>> &VEC) {
  for (vector<T> const &i : VEC) {
    for (T const &j : i) cout << j;
    cout << endl;
  }
}
template <typename T>
int cntDigits(const T &N) {
  return (static_cast<int>(floor(log10(N))) + 1);
}
template <typename T>
bool isPowOfTwo(const T &N) {
  return (N && (!(N & (N - 1))));
}
template <typename T>
T lcm(T a, T b) {
  return ((a * b) / __gcd(a, b));
}
bool dblEqual(const long double &a, const long double &b) {
  return abs(a - b) < EPS;
}
void TEST_CASES() {
  int r{}, c{}, x{}, y{};
  cin >> r >> c >> x >> y;
  vector<vector<char>> mat(r, vector<char>(c));
  cin >> mat;
  int spent{};
  for (auto const &row : mat) {
    int temp_col{c};
    for (int j{}; j < c;) {
      if (temp_col >= 2) {
        if (x + x < y) {
          if (row.at(j) == '.' && row.at(j + 1) == '.') {
            spent += x + x;
            j += 2;
            temp_col -= 2;
          } else if (row.at(j) == '.' && row.at(j + 1) != '.') {
            spent += x;
            ++j;
            --temp_col;
          } else {
            ++j;
            --temp_col;
          }
        } else {
          if (row.at(j) == '.' && row.at(j) == '.') {
            spent += y;
            j += 2;
            temp_col -= 2;
          } else if (row.at(j) == '.' && row.at(j) != '.') {
            spent += x;
            ++j;
            --temp_col;
          } else {
            ++j;
            --temp_col;
          }
        }
      } else {
        if (row.at(j) == '.') spent += x;
        ++j;
        --temp_col;
      }
    }
  }
  cout << spent << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cerr.setf(std::ios::boolalpha);
  cout << std::fixed;
  cout << std::setprecision(6);
  unsigned TT{};
  cin >> TT;
  while (TT--) {
    TEST_CASES();
  }
  return 0;
}
