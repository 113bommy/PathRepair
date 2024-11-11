#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2>& pr) {
  return os << pr.first << ' ' << pr.second;
}
template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& pr) {
  return is >> pr.first >> pr.second;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& el : v) os << el << endl;
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& el : v) is >> el;
  return is;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  a[0] = 1;
  a[n - 1] = 1;
  bool changed = 1;
  while (changed) {
    changed = 0;
    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] + 1 < a[i]) {
        a[i] = a[i - 1] + 1;
        changed = 1;
      }
    }
    for (int i = n - 1; i >= 1; i--) {
      if (a[i + 1] + 1 < a[i]) {
        a[i] = a[i + 1] + 1;
        changed = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i]);
  }
  cout << ans << endl;
  return 0;
}
