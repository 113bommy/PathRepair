#include <bits/stdc++.h>
using namespace std;
template <class T>
string to_string(T v) {
  bool f = 0;
  string res;
  for (auto& x : v) {
    res += (f ? " " : "");
    f = 1;
    res += to_string(x);
  }
  return res;
}
string to_string(const char c) { return string(1, c); }
string to_string(const bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(const string s) { return s; }
string to_string(const vector<bool> v) {
  string res;
  for (int i = (0); (1) > 0 ? i < ((int)(v).size()) : i > ((int)(v).size());
       i += (1))
    res += (char)('0' + v[i]);
  return res;
}
template <class T>
void read(T& x) {
  cin >> x;
}
template <class T>
void read(vector<T>& a) {
  for (auto& x : a) read(x);
}
template <class T, size_t S>
void read(array<T, S>& a) {
  for (auto& x : a) read(x);
}
template <class T, class... O>
void read(T& x, O&... o) {
  read(x);
  read(o...);
}
template <class T>
void write(const T& x) {
  cout << to_string(x);
}
template <class T, class... O>
void write(const T& x, const O&... o) {
  write(x);
  write(o...);
}
void write() { write("\n"); }
template <class T, class U>
void vti(vector<T>& v, U x, size_t n) {
  v = vector<T>(n, x);
}
template <class T, class U>
void vti(vector<T>& v, U x, size_t n, size_t m...) {
  v = vector<T>(n);
  for (auto& i : v) vti(i, x, m);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  read(t);
  while (t--) {
    long long n, k;
    read(n, k);
    vector<array<long long, 2>> a(n);
    for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1))
      read(a[i][0]), a[i][1] = i + 1;
    sort((a).begin(), (a).end());
    for (int i = (1); (1) > 0 ? i < (n) : i > (n); i += (1))
      a[i][0] += a[i - 1][0];
    long long kl = (k + 1) / 2;
    bool ok = 0;
    int i1, j1;
    for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) {
      if (kl <= a[i][0] && a[i][0] <= k) {
        i1 = 0;
        j1 = i + 1;
        ok = 1;
        break;
      } else if (a[i][0] > k) {
        auto it = upper_bound((a).begin(), (a).end(),
                              array<long long, 2>({a[i][0] - k, 0}));
        if (it != a.end() && kl <= a[i][0] - (*it)[0] &&
            a[i][0] - (*it)[0] <= k) {
          i1 = it - a.begin();
          j1 = i + 1;
          ok = 1;
          break;
        }
      }
    }
    write(ok ? j1 - i1 : -1);
    write();
    if (ok) {
      for (int i = (i1); (1) > 0 ? i < (j1) : i > (j1); i += (1))
        write(a[i][1], " ");
      write();
    }
  }
}
