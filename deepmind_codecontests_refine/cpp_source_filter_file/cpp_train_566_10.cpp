#include <bits/stdc++.h>
using namespace std;
const int inf = 2e8 + 5;
const long long l_inf = 9e18 + 5;
template <typename T>
inline T mod(T a, T b) {
  return (a % b + b) % b;
}
template <typename T, typename T2>
ostream &operator<<(ostream &s, const pair<T, T2> &p) {
  return s << p.first << ' ' << p.second << ' ';
}
template <typename T, typename T2>
istream &operator>>(istream &s, pair<T, T2> &p) {
  return s >> p.first >> p.second;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
  for (auto it : v) s << it << ' ';
  return s;
}
template <typename T>
istream &operator>>(istream &s, vector<T> &v) {
  for (auto it = (v).begin(), it_ = (v).end(); it != it_; it++) s >> *it;
  return s;
}
template <typename T>
void read_range(T beg, T end) {
  while (beg != end) cin >> *beg++;
}
template <typename T>
void print_range(T beg, T end) {
  while (beg != end) cout << *beg++ << ' ';
}
struct reader {
  template <typename T>
  reader &operator,(T &v) {
    cin >> v;
    return *this;
  }
} rdr;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << ", ";
    return *this;
  }
} dbg;
int gcd(int a, int b) {
  while (b) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
int ar[(int)(1e5 + 5)];
vector<int> res;
string name[4];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, x, y;
  rdr, n, x, y;
  ;
  read_range(ar, ar + n);
  name[1] = "Vanya\n";
  name[2] = "Vova\n";
  name[3] = "Both\n";
  long long lcm = x * y / gcd(x, y);
  long long x_inc = lcm / x;
  long long y_inc = lcm / y;
  map<long long, int> attack;
  for (long long i = x_inc; i <= lcm; i += x_inc) {
    attack[i] += 1;
  }
  for (long long i = y_inc; i <= lcm; i += y_inc) {
    attack[i] += 2;
  }
  for (auto it = (attack).begin(), it_ = (attack).end(); it != it_; it++) {
    if (it->second == 3) res.push_back(it->second);
    res.push_back(it->second);
  }
  int second = attack.size();
  for (int i = 0; i < n; i++) {
    ar[i]--;
    cout << name[res[ar[i] % second]];
  }
  return 0;
}
