#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
istream &operator>>(istream &cin, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return cin;
}
template <typename T>
ostream &operator<<(ostream &cout, vector<T> &v) {
  for (auto &i : v) cout << i << " ";
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> &v) {
  cout << v.first << " " << v.second << "  ";
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, vector<vector<T> > &v) {
  for (auto &i : v) cout << i << '\n';
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, map<T1, T2> &v) {
  for (auto &i : v) cout << i.first << " " << i.second << "  ";
  return cout;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &cout, unordered_map<T1, T2> &v) {
  for (auto &i : v) cout << i.first << " " << i.second << "  ";
  return cout;
}
void solution();
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solution();
  return 0;
}
void solution() {
  ll a, b;
  cin >> a >> b;
  ;
  long long t = abs(a) + abs(b);
  if (a >= 0 and b >= 0) {
    cout << "0 " << t << " " << t << " 0";
  } else if (a <= 0 and b <= 0) {
    cout << t << " 0 0 " << t;
  } else if (a >= 0 and b <= 0) {
    cout << "0 " << -t << " " << t << " 0";
  } else {
    cout << -t << " 0 0 " << t;
  }
}
