#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
bool iseven(long long n) {
  if ((n & 1) == 0) return true;
  return false;
}
void print(long long t) { cout << t; }
void print(int t) { cout << t; }
void print(string t) { cout << t; }
void print(char t) { cout << t; }
void print(double t) { cout << t; }
void print(long double t) { cout << t; }
template <class T, class V>
void print(pair<T, V> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class V>
void print(map<T, V> v);
template <class T>
void print(multiset<T> v);
template <class T, class V>
void print(pair<T, V> p) {
  cout << "{";
  print(p.first);
  cout << ",";
  print(p.second);
  cout << "}";
}
template <class T>
void print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    print(i);
    cout << " ";
  }
  cout << "]";
}
void run() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void solve() {
  long long n;
  cin >> n;
  long long a, b;
  long long m = 0, c = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    cin >> b;
    if (a > b) {
      m++;
    } else if (a < b) {
      c++;
    } else {
      m++;
      c++;
    }
  }
  if (m > c) {
    cout << "Mishka";
  } else if (c < m) {
    cout << "Chris";
  } else {
    cout << "Friendship is magic!^^";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
