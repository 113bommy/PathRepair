#include <bits/stdc++.h>
using namespace std;
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (int i = 0; i < (int)vec.size(); ++i) is >> vec[i];
  return is;
}
template <class T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (int i = 0; i < (int)vec.size(); ++i) os << vec[i] << " ";
  return os;
}
template <class T>
istream& operator>>(istream& is, pair<T, T>& a) {
  is >> a.first >> a.second;
  return is;
}
const double pi = acos(-1.0);
const long long mod = 998244353;
const long long INF = 1e15;
const int inf = 2e9;
const int maxlen = (int)2e5 + 5;
const double eps = 1e-4;
int solve() {
  int k;
  cin >> k;
  int p2 = 1;
  while (p2 <= k) p2 <<= 1;
  int f = 1;
  while ((f << 1) < 300000) f <<= 1;
  cout << 3 << " " << 3 << "\n";
  cout << f << " " << k << " " << p2 << "\n";
  cout << p2 << " " << f << " " << f << "\n";
  cout << p2 << " " << f << " " << k;
  return 0;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
