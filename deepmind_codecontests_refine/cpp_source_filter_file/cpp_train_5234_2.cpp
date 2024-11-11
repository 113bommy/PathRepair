#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void google(int t) { cout << "Case #" << t << ": "; }
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
int sum(long long n) {
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
void solve(int case_number) {
  long long n, s, p, q, ans, i;
  cin >> n >> s;
  long long l = sum(n);
  if (n <= s) {
    cout << 0 << "\n";
    ;
    return;
  }
  ans = 0;
  long long pw = 1;
  for (i = 0; i <= 18; i++) {
    p = (n / pw) % 10;
    q = pw * ((10 - p));
    n = n + q;
    ans = ans + q;
    if (sum(n) <= s) {
      break;
    }
    pw = pw * 10;
  }
  cout << ans << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  long long i;
  t = 1;
  cin >> t;
  for (int case_number = 1; case_number <= t; case_number++) {
    solve(case_number);
  }
}
