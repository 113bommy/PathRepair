#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
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
vector<bool> p(100002, true);
vector<long long> vect;
void sieve(long long max) {
  p[0] = false;
  p[1] = false;
  for (int i = 2; i * i < max; ++i) {
    if (p[i]) {
      for (int j = i * i; j < max; j += i) {
        p[j] = false;
      }
    }
  }
}
bool check(long long mid, long long A[], long long c, int n) {
  int i;
  long long a = -1e15;
  for (i = 0; i < n; i++) {
    if (c == 0) {
      break;
    }
    if ((A[i] - a) >= mid) {
      c--;
      a = A[i];
    }
  }
  return (c == 0);
}
void solve() {
  long long i, j, k, l, n, c, A[2110];
  long long a = 1;
  long long mnex = INT_MIN;
  string s, ans;
  cin >> n >> k;
  cin >> s;
  ans = s;
  for (i = 1; i < n; i++) {
    if (s.substr(i) == s.substr(0, n - i)) {
      ans = s.substr(n - i);
      break;
    }
  }
  for (i = 1; i < k; i++) {
    ans = s + ans;
  }
  cout << ans << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sieve(100002);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}
