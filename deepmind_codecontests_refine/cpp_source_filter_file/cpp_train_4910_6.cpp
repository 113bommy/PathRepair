#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
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
const long long inf = 1000000001;
const long long INF = (long long)1e18 + 1;
const long long MOD = 1000000007;
const double pi = 3.14159265358979323846;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dy2[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n;
vector<int> a, b;
int solve1() {
  set<int> te;
  for (int i = 0; i < (n); i++) {
    if (a[i] >= 0) {
      te.insert(a[i]);
    }
  }
  int res = 0;
  int nex = b.back() + 1;
  while (nex < n) {
    if (te.count(nex)) {
      te.insert(b[res]);
      res++;
      nex++;
    } else {
      res = -1;
      break;
    }
  }
  return res;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ;
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < (n); i++) {
    cin >> b[i];
    b[i]--;
  }
  if (b.back() >= 0) {
    int last = b.back();
    int i = 0;
    bool flag = true;
    for (int j = n - 1 - last; j < n; j++) {
      if (b[j] != i) flag = false;
      i++;
    }
    if (flag) {
      int res = solve1();
      if (res >= 0) {
        cout << res << endl;
        return 0;
      }
    }
  }
  int ng = 0, ok = 2 * n;
  while (ng + 1 < ok) {
    int mid = (ng + ok) / 2;
    bool flag = true;
    for (int i = 0; i < (n); i++) {
      if (b[i] >= 0) {
        int t = b[i] - n + 1 + mid;
        if (t < i + 2) {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
}
