#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long M = 1e9 + 7;
int prime[10] = {0};
void seive(int n) {
  for (int i = 2; i <= n; i++) {
    if (prime[i])
      continue;
    else {
      for (int j = 2 * i; j <= n; j += i) prime[j] = 1;
    }
  }
}
void solve() {
  string str;
  cin >> str;
  int ab = 0, ba = 0;
  int n = str.length();
  for (int i = 0; i < n - 1; i++) {
    if (str[i] == 'a' && str[i + 1] == 'b') ab++;
  }
  for (int i = 0; i < n - 1; i++) {
    if (str[i] == 'b' && str[i + 1] == 'a') ba++;
  }
  if (ab == ba)
    cout << str;
  else if (ab == (ba + 1)) {
    for (int i = 0; i < n - 1; i++) cout << str[i];
    cout << "a";
  } else {
    for (int i = 0; i < n - 1; i++) cout << str[i];
    cout << "b";
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
