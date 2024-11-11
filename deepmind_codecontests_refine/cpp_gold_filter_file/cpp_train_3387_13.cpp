#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << " : " << it.second << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
void go() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  go();
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int lo = 0, hi = n, ans = 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int z = 0, yes = 0;
    for (int i = 0; i < mid; i++) {
      if (a[i] == 0) z++;
    }
    if (z <= k) yes = 1;
    for (int i = mid; i < n; ++i) {
      if (a[i] == 0) z++;
      if (a[i - mid] == 0) z--;
      if (z <= k) yes = 1;
    }
    if (yes) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << ans << '\n';
  int z = 0;
  for (int i = 0; i < ans; i++) {
    if (a[i] == 0) z++;
  }
  if (z <= k) {
    for (int i = 0; i < ans; i++) cout << 1 << ' ';
    for (int i = ans; i < n; ++i) cout << a[i] << ' ';
    return 0;
  }
  for (int i = ans; i < n; ++i) {
    if (a[i - ans] == 0) z--;
    if (a[i] == 0) ++z;
    if (z <= k) {
      for (int j = 0; j <= i - ans; j++) cout << a[j] << ' ';
      for (int j = i - ans + 1; j < i; j++) cout << 1 << ' ';
      for (int j = i; j < n; j++) cout << a[j] << ' ';
      return 0;
    }
  }
}
