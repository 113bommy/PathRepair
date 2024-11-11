#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
int grundy(int x) {
  if (x == 0) return 0;
  if (x & 1) return 0;
  int a = grundy(x - 1);
  int b = ((x & 1) == 0) ? grundy(x / 2) : -1;
  if (a && b) return 0;
  if (a != 1 && b != 1) return 1;
  return 2;
}
int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  int win = 0;
  for (int i = 0; i < (int)(n); i++) {
    int x;
    cin >> x;
    if (k % 2 == 0) {
      if (x < 3)
        win ^= x;
      else
        win ^= 1 & x ^ 1;
    } else {
      win ^= grundy(x);
    }
  }
  puts(win ? "Kevin" : "Nicky");
  return 0;
}
