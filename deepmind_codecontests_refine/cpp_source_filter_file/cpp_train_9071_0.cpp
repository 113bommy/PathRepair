#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int first = 0;
  cerr << '{';
  for (auto &i : x) cerr << (first++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long int calc(long long int num) {
  long long int od = 0, ev = 0, flag = 0, test = 1, sum;
  while (test <= num) {
    num -= test;
    if (!flag) {
      od = (od + test) % mod;
    } else {
      ev = (ev + test) % mod;
    }
    test *= 2;
    flag ^= 1;
  }
  if (!flag) {
    od = (od + num) % mod;
  } else {
    ev = (ev + num) % mod;
  }
  sum = (od % mod * od % mod + (ev + 1) % mod * ev % mod) % mod;
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int l, r;
  cin >> l >> r;
  cout << (calc(r) - calc(l - 1)) % mod;
  return 0;
}
