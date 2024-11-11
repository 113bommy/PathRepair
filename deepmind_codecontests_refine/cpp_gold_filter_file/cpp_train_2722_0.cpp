#include <bits/stdc++.h>
using namespace std;
namespace io {
inline int rdi() {
  int v;
  cin >> v;
  return v;
}
inline long long rdll() {
  long long v;
  cin >> v;
  return v;
}
inline string rds() {
  string s;
  cin >> s;
  return s;
}
inline char rdc() {
  char c;
  cin >> c;
  return c;
}
template <class T>
void rdv(T beg_iter, T end_iter) {
  for (; beg_iter != end_iter; ++beg_iter) cin >> *beg_iter;
}
inline void wri(const int v) { cout << v; }
inline void wrll(const long long &v) { cout << v; }
inline void wrs(const string &s) { cout << s; }
inline void wrc(const char c) { cout << c; }
template <class T>
void wrv(T beg_iter, T end_iter, string separator = " ",
         string end_of_line = "\n") {
  for (; beg_iter != end_iter; ++beg_iter) {
    cout << *beg_iter;
    cout << separator;
  }
  cout << end_of_line;
}
}  // namespace io
using namespace io;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    x = (x * x) % p;
  }
  return res;
}
void solve();
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
void solve() {
  long long n = rdll();
  vector<string> A(n);
  for (long long i = 0; i < n; ++i) cin >> A[i];
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      if (A[i][j] == '.' && i + 1 < n && i - 1 >= 0 && j + 1 < n &&
          j - 1 >= 0) {
        if (A[i + 1][j] == '.' && A[i - 1][j] == '.' && A[i][j + 1] == '.' &&
            A[i][j - 1] == '.') {
          A[i][j] = '#';
          A[i + 1][j] = '#';
          A[i - 1][j] = '#';
          A[i][j + 1] = '#';
          A[i][j - 1] = '#';
        }
      }
    }
  }
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      if (A[i][j] == '.') {
        cout << "NO" << '\n';
        return;
      }
    }
  }
  cout << "YES" << '\n';
}
