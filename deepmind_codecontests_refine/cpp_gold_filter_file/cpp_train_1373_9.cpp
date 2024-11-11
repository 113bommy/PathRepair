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
long long calc(const long &x) {
  if (x == 0 || x == 6 || x == 9)
    return 6;
  else if (x == 1)
    return 2;
  else if (x == 2 || x == 3 || x == 5)
    return 5;
  else if (x == 4)
    return 4;
  else if (x == 7)
    return 3;
  else
    return 7;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long x1, x2, y1, y2;
  long long x3, x4, y3, y4;
  long long x5, x6, y5, y6;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;
  cin >> x5 >> y5 >> x6 >> y6;
  x2 -= x1;
  x3 -= x1;
  x4 -= x1;
  x5 -= x1;
  x6 -= x1;
  y2 -= y1;
  y3 -= y1;
  y4 -= y1;
  y5 -= y1;
  y6 -= y1;
  x1 = 0;
  y1 = 0;
  long long area = x2 * y2;
  long long left1 = max(x1, min(x2, x3));
  long long bottom1 = max(y1, min(y2, y3));
  long long right1 = max(x1, min(x2, x4));
  long long top1 = max(y1, min(y2, y4));
  long long b1Area = (right1 - left1) * (top1 - bottom1);
  long long left2 = max(x1, min(x2, x5));
  long long bottom2 = max(y1, min(y2, y5));
  long long right2 = max(x1, min(x2, x6));
  long long top2 = max(y1, min(y2, y6));
  long long b2Area = (right2 - left2) * (top2 - bottom2);
  long long width, height, interArea;
  if (right1 <= left2 || right2 <= left1 || top1 <= bottom2 ||
      top2 <= bottom1) {
    if (0 < area - (b1Area + b2Area))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  } else {
    if ((left1 <= left2 && right2 <= right1 && top2 <= top1 &&
         bottom1 <= bottom2) ||
        (left2 <= left1 && right1 <= right2 && top1 <= top2 &&
         bottom2 <= bottom1)) {
      width = max(right1, right2) - min(left1, left2);
      height = max(top1, top2) - min(bottom1, bottom2);
      if (0 < area - width * height)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    } else {
      width = min(right1, right2) - max(left1, left2);
      height = min(top1, top2) - max(bottom1, bottom2);
      interArea = max(0LL, width * height);
      if (0 < area - ((b1Area + b2Area) - interArea))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
