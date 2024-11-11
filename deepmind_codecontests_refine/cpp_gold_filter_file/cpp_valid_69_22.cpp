#include <bits/stdc++.h>
using namespace std;
void print(long long t) { cerr << t; }
void print(string t) { cerr << t; }
void print(char t) { cerr << t; }
void print(long double t) { cerr << t; }
void print(double t) { cerr << t; }
void print(unsigned long long t) { cerr << t; }
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
  cerr << "{";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << "}";
}
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long inf = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void zz() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
long long f(string x, string y) {
  long long n = x.size();
  long long m = y.size();
  long long i = 0;
  long long j = 0;
  long long cnt = 0;
  while (i < n && j < m) {
    if (x[i] == y[j])
      i += 1, j += 1;
    else {
      i += 1;
      cnt += 1;
    }
  }
  cnt += (n - i);
  cnt += (m - j);
  return cnt;
}
vector<string> v;
void slv() {
  string s;
  cin >> s;
  long long x = inf;
  for (long long i = 0; i < 62; i++) {
    x = min(x, f(s, v[i]));
  }
  cout << x << endl;
}
int32_t main() {
  zz();
  for (long long i = 0; i < 62; i++) {
    long long x = (1LL << i);
    v.emplace_back(to_string(x));
  };
  long long t = 1;
  cin >> t;
  while (t--) {
    slv();
  }
}
