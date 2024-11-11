#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
bool uax(T &a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T &a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
mt19937 rnd(1928);
int n, m;
vector<int> a;
bool check(int x) {
  int pred = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= pred) {
      if (pred - a[i] <= x) {
        continue;
      } else {
        return false;
      }
    } else {
      if (pred + m - a[i] <= x) {
        continue;
      } else {
        pred = a[i];
      }
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = -1, r = m + 1, mid;
  while (r > l + 1) {
    mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r;
}
