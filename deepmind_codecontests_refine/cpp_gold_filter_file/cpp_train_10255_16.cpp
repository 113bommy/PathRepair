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
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d", &n);
  vector<int> d(n);
  for (int i = 0; i < (int)(n); i++) {
    int x;
    scanf("%d", &x);
    x--;
    d[x] = i;
  }
  vector<int> a(n);
  for (int i = 0; i < (int)(n); i++) {
    int x;
    scanf("%d", &x);
    x--;
    a[i] = d[x];
  }
  vector<pair<int, int> > ans;
  int c = 0;
  for (int i = 0; i < (int)(n); i++) {
    int t = min_element(a.begin() + i, a.end()) - a.begin();
    for (int j = t - 1; i <= j; j--) {
      if (t <= a[j]) {
        ans.emplace_back(t, j);
        swap(a[t], a[j]);
        c += t - j;
        t = j;
      }
    }
  }
  printf("%d\n", c);
  printf("%d\n", ans.size());
  for (__typeof((ans).rbegin()) it = (ans).rbegin(); it != (ans).rend(); it++)
    printf("%d %d\n", it->first + 1, it->second + 1);
  return 0;
}
