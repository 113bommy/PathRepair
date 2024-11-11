#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <typename T, typename U>
inline void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
class Debugger {
 public:
  Debugger(const std::string& _separator = " - ")
      : first(true), separator(_separator) {}
  template <typename ObjectType>
  Debugger& operator,(const ObjectType& v) {
    if (!first)
    std:
      cerr << separator;
    std::cerr << v;
    first = false;
    return *this;
  }
  ~Debugger() {
  std:
    cerr << endl;
  }

 private:
  bool first;
  std::string separator;
};
string solve(string s) {
  long long sum;
  sum = 0;
  for (int i = 0; i < s.length(); i++) {
    sum += s[i] - '0';
  }
  return to_string(sum);
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<int> vec(m + 1);
  for (int i = 0; i < m + 1; i++) {
    cin >> vec[i];
  }
  int ans = 0;
  int a, b;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    a = vec[i];
    b = vec[m];
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((a ^ b) % 2 == 1) {
        cnt++;
      }
      a = a >> 1;
      b = b >> 1;
    }
    if (cnt <= k) {
      ans++;
    }
  }
  cout << ans;
}
