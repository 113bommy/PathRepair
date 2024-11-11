#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const long long mod = 1000000007;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < int(n); i++) cin >> a[i];
  sort((a).begin(), (a).end());
  set<int> s;
  for (int i = 0; i < int(n); i++) {
    s.insert(a[i]);
  }
  if (s.size() > 3) {
    cout << -1 << endl;
    return 0;
  }
  if (s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (s.size() == 2) {
    if (((a[n - 1] - a[0])) % 2 == 0) {
      cout << (a[n - 1] - a[0]) / 2 << endl;
      return 0;
    } else {
      cout << a[n - 1] - a[0] << endl;
      return 0;
    }
  }
  vector<int> v;
  for (int i : s) {
    v.push_back(i);
  }
  sort((v).begin(), (v).end());
  if ((v[0] + v[2]) % 2 == 1) {
    cout << -1 << endl;
    return 0;
  }
  if ((v[0] + v[2]) != v[1] * 2) {
    cout << -1 << endl;
  } else {
    cout << (v[2] - v[0]) / 2 << endl;
  }
  return 0;
}
