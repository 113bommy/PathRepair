#include <bits/stdc++.h>
using namespace std;
namespace {
using Integer = long long;
template <class T, class S>
istream& operator>>(istream& is, pair<T, S>& p) {
  return is >> p.first >> p.second;
}
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (T& val : vec) is >> val;
  return is;
}
template <class T>
istream& operator,(istream& is, T& val) {
  return is >> val;
}
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {
  return os << p.first << " " << p.second;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); i++)
    os << vec[i] << (i == vec.size() - 1 ? "" : " ");
  return os;
}
template <class T>
ostream& operator,(ostream& os, const T& val) {
  return os << " " << val;
}
template <class H>
void print(const H& head) {
  cout << head;
}
template <class H, class... T>
void print(const H& head, const T&... tail) {
  cout << head << " ";
  print(tail...);
}
template <class... T>
void println(const T&... values) {
  print(values...);
  cout << endl;
}
template <class H>
void eprint(const H& head) {
  cerr << head;
}
template <class H, class... T>
void eprint(const H& head, const T&... tail) {
  cerr << head << " ";
  eprint(tail...);
}
template <class... T>
void eprintln(const T&... values) {
  eprint(values...);
  cerr << endl;
}
class range {
  Integer start_, end_, step_;

 public:
  struct range_iterator {
    Integer val, step_;
    range_iterator(Integer v, Integer step) : val(v), step_(step) {}
    Integer operator*() { return val; }
    void operator++() { val += step_; }
    bool operator!=(range_iterator& x) {
      return step_ > 0 ? val < x.val : val > x.val;
    }
  };
  range(Integer len) : start_(0), end_(len), step_(1) {}
  range(Integer start, Integer end) : start_(start), end_(end), step_(1) {}
  range(Integer start, Integer end, Integer step)
      : start_(start), end_(end), step_(step) {}
  range_iterator begin() { return range_iterator(start_, step_); }
  range_iterator end() { return range_iterator(end_, step_); }
};
inline string operator"" _s(const char* str, size_t size) {
  return move(string(str));
}
constexpr Integer my_pow(Integer x, Integer k, Integer z = 1) {
  return k == 0    ? z
         : k == 1  ? z * x
         : (k & 1) ? my_pow(x * x, k >> 1, z * x)
                   : my_pow(x * x, k >> 1, z);
}
constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z = 1) {
  return k == 0    ? z % M
         : k == 1  ? z * x % M
         : (k & 1) ? my_pow_mod(x * x % M, k >> 1, M, z * x % M)
                   : my_pow_mod(x * x % M, k >> 1, M, z);
}
constexpr unsigned long long operator"" _ten(unsigned long long value) {
  return my_pow(10, value);
}
inline int k_bit(Integer x, int k) { return (x >> k) & 1; }
mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(
               chrono::steady_clock::now().time_since_epoch())
               .count());
template <class T>
string join(const vector<T>& v, const string& sep) {
  stringstream ss;
  for (size_t i = 0; i < v.size(); i++) {
    if (i > 0) ss << sep;
    ss << v[i];
  }
  return ss.str();
}
inline string operator*(string s, int k) {
  string ret;
  while (k) {
    if (k & 1) ret += s;
    s += s;
    k >>= 1;
  }
  return ret;
}
}  // namespace
constexpr long long mod = 9_ten + 7;
int solve(int a, int b, int h, int w, vector<int>& k) {
  int ret = 114514893;
  for (int i = 0; i < (1 << 18); i++) {
    int cnt = 0;
    long long hh = h;
    long long ww = w;
    for (int j = 0; j < min<int>(18, k.size()); j++) {
      if ((i >> j) & 1) {
        if (hh < a) {
          hh *= k[j];
          cnt++;
        } else {
          if (ww < b) {
            ww *= k[j];
            cnt++;
          }
        }
      } else {
        if (ww < b) {
          ww *= k[j];
          cnt++;
        } else if (hh < a) {
          hh *= k[j];
          cnt++;
        }
      }
    }
    for (int j = 18; j < k.size() && j < 40; j++) {
      if (ww < b) {
        ww *= k[j];
        cnt++;
      } else if (hh < a) {
        hh *= k[j];
        cnt++;
      }
    }
    if (hh < b) continue;
    if (ww < b) continue;
    ret = min(ret, cnt);
  }
  return ret;
}
int main() {
  int a, b, h, w, n;
  cin >> a, b, h, w, n;
  vector<int> k(n);
  cin >> k;
  sort(k.rbegin(), k.rend());
  int ans = min(solve(a, b, h, w, k), solve(b, a, h, w, k));
  if (ans > n) ans = -1;
  println(ans);
  return 0;
}
