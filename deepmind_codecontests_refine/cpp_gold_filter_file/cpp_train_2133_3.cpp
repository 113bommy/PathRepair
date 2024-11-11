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
int n;
long long int A, B, l, t, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> n;
  for (int i = 0; i < (int)(n); i++) {
    cin >> l >> t >> m;
    l--;
    long long int L = 0, R = 1000001;
    long long int lmost = A + l * B;
    while (L + 1 < R) {
      long long int med = (L + R) / 2;
      long long int rmost = A + (l + med - 1) * B;
      if (rmost > t || lmost * med + B * (med) * (med - 1) / 2 > t * m)
        R = med;
      else
        L = med;
    }
    if (!L)
      cout << -1 << endl;
    else
      cout << l + L << endl;
  }
  return 0;
}
