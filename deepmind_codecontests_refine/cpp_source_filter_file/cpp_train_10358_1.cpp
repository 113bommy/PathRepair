#include <bits/stdc++.h>
using namespace std;
void debugger(long long int t) { cerr << t; }
void debugger(int t) { cerr << t; }
void debugger(string t) { cerr << t; }
void debugger(char t) { cerr << t; }
void debugger(long double t) { cerr << t; }
void debugger(double t) { cerr << t; }
void debugger(unsigned long long int t) { cerr << t; }
template <class T, class V>
void debugger(pair<T, V> p);
template <class T>
void debugger(vector<T> v);
template <class T>
void debugger(set<T> v);
template <class T, class V>
void debugger(map<T, V> v);
template <class T>
void debugger(multiset<T> v);
template <class T, class V>
void debugger(pair<T, V> p) {
  cerr << "{";
  debugger(p.first);
  cerr << ",";
  debugger(p.second);
  cerr << "}";
}
template <class T>
void debugger(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    debugger(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void debugger(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    debugger(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void debugger(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    debugger(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void debugger(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    debugger(i);
    cerr << " ";
  }
  cerr << "]";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const long long int N = 1e5;
vector<char> o(3);
vector<long long int> a(4);
long long int sol(long long int i, vector<long long int> a) {
  if (i == 3) return a[0];
  long long int ans = 1e9;
  for (long long int x = 0; x < ((int)(a).size()); x++) {
    for (long long int y = 0; y < ((int)(a).size()); y++) {
      if (x == y) continue;
      long long int cur;
      if (o[i] == '+')
        cur = a[x] + a[y];
      else
        cur = a[x] * a[y];
      vector<long long int> v;
      for (long long int k = 0; k < ((int)(a).size()); k++)
        if (k != x && k != y) v.emplace_back(a[k]);
      v.emplace_back(cur);
      ans = min(ans, sol(i + 1, v));
    }
  }
  return ans;
}
void JAISHREERAM() {
  long long int n, ans = 0;
  for (long long int i = 0; i < 4; i++) cin >> a[i];
  for (long long int i = 0; i < 3; i++) cin >> o[i];
  ans = sol(0, a);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T = 1;
  for (int t = 1; t <= T; t++) {
    JAISHREERAM();
  }
  return 0;
}
