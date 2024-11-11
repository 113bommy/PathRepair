#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& o, const pair<T, U>& x) {
  o << "(" << x.first << ", " << x.second << ")";
  return o;
}
template <typename T>
ostream& operator<<(ostream& o, const vector<T>& x) {
  o << "[";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "]";
  return o;
}
template <typename T>
ostream& operator<<(ostream& o, const set<T>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T>
ostream& operator<<(ostream& o, const multiset<T>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T>
ostream& operator<<(ostream& o, const unordered_set<T>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T>
ostream& operator<<(ostream& o, const unordered_multiset<T>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T, typename U>
ostream& operator<<(ostream& o, const map<T, U>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T, typename U>
ostream& operator<<(ostream& o, const multimap<T, U>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T, typename U>
ostream& operator<<(ostream& o, const unordered_map<T, U>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
template <typename T, typename U>
ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) {
  o << "{";
  int b = 0;
  for (auto& a : x) o << (b++ ? ", " : "") << a;
  o << "}";
  return o;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> S(5000);
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (x <= 2048) S[x]++;
    }
    for (int i = 2; i <= 1024; i *= 2) {
      if (S[i] >= 2) {
        S[2 * i] += 2;
        S[i] -= 2;
      }
    }
    if (S[2048] > 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
