#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Outln(const string &sep, const T &val) {
  cout << val << '\n';
}
template <typename T, typename... Args>
void Outln(const string &sep, const T &val, Args... args) {
  cout << val << sep;
  Outln(sep, std::forward<Args>(args)...);
}
template <typename T>
void OutN(T x) {
  size_t i, len = x.size() - 1;
  for (i = 0; i < len; i++) cout << x[i] << " ";
  cout << x[len] << '\n';
}
template <typename T>
void Outit(T x) {
  auto end = x.end();
  end--;
  for (auto it = x.begin(); it != end; it++) cout << *it << " ";
  cout << *end << '\n';
}
template <typename T>
void Debug(const T &val) {
  cerr << val << '\n';
}
template <typename T, typename... Args>
void Debug(const T &val, Args... args) {
  cerr << val << ' ';
  Debug(std::forward<Args>(args)...);
}
template <typename T>
inline bool Max(T &x, const T &y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool Min(T &x, const T &y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
using V = vector<T>;
template <typename T>
using VV = V<V<T> >;
inline bool isSame(const string &first, const string &second) {
  return first.compare(second) == 0;
}
inline bool isLess(const string &first, const string &second) {
  return first.compare(second) < 0;
}
inline bool isGreater(const string &first, const string &second) {
  return first.compare(second) > 0;
}
inline string Str(const char &ch, const int &n) { return string(n, ch); }
inline string Str(const int &n, const char &ch) { return string(n, ch); }
vector<string> getStrLine() {
  vector<string> v;
  string str;
  getline(cin, str);
  istringstream iss(str);
  for (string word; iss >> word;) v.push_back(word);
  return v;
}
static const long long MOD = 1e9 + 7;
static const double PI = 3.141592653589793;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int k, l, m, n;
  int d;
  cin >> k;
  cin >> l;
  cin >> m;
  cin >> n;
  cin >> d;
  int ans = 0;
  int i;
  for ((i) = (1); (i) <= (d); (i)++) {
    if (i % k == 0)
      ans++;
    else if (i % l == 0)
      ans++;
    else if (i % m == 0)
      ans++;
    else if (i % n == 0)
      ans++;
  }
  cout << (ans) << '\n';
  return 0;
}
