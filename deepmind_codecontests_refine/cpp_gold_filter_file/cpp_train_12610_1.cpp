#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0},
          dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = (0); (1) > 0 ? i < ((int)(v).size()) : i > ((int)(v).size());
       i += (1))
    res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (int i = (0); (1) > 0 ? i < (S) : i > (S); i += (1))
    res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto& x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
inline int bitCount(int number) { return __builtin_popcount(number); }
inline int bitCount(long long number) { return __builtin_popcount(number); }
template <class H, class... T>
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
template <class T>
bool umin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
const int MOD = 1e9 + 7;
const int N = 2e6 + 5;
const long long INF = 9e19;
const long double PI = acos((long double)-1);
const int M = 501;
void solve() {
  int n;
  read(n);
  string s;
  read(s);
  int z = -n / 3, o = -n / 3, t = -n / 3;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0')
      z++;
    else if (s[i] == '1')
      o++;
    else
      t++;
  }
  for (int i = 0; i < n; ++i) {
    if (z < 0) {
      if (s[i] == '1' && o > 0) {
        s[i] = '0';
        o--;
        z++;
      } else if (s[i] == '2' && t > 0) {
        s[i] = '0';
        t--;
        z++;
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (t < 0) {
      if (s[i] == '1' && o > 0) {
        s[i] = '2';
        o--;
        t++;
      } else if (s[i] == '0' && z > 0) {
        s[i] = '2';
        z--;
        t++;
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (o < 0) {
      if (s[i] == '0' && z > 0) {
        s[i] = '1';
        z--;
        o++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (o < 0) {
      if (s[i] == '2' && t > 0) {
        s[i] = '1';
        t--;
        o++;
      }
    }
  }
  print(s);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (int i = (0); (1) > 0 ? i < (t) : i > (t); i += (1)) {
    solve();
  }
  return 0;
}
