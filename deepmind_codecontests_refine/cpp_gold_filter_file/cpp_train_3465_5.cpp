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
void _print(T a[], V sz);
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
  cerr << " -> ";
  _print(p.second);
  cerr << "}" << endl;
}
template <class T, class V>
void _print(T a[], V sz) {
  for (V i = 0; i < sz; i++) {
    _print(a[i]);
    cerr << " ";
  }
  cerr << endl;
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
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
  cerr << "]" << endl;
}
void _printall(long long t) { cout << t; }
void _printall(int t) { cout << t; }
void _printall(string t) { cout << t; }
void _printall(char t) { cout << t; }
void _printall(long double t) { cout << t; }
void _printall(double t) { cout << t; }
void _printall(unsigned long long t) { cout << t; }
template <class T, class V>
void _printall(T a[], V sz);
template <class T, class V>
void _printall(pair<T, V> p);
template <class T>
void _printall(vector<T> v);
template <class T>
void _printall(set<T> v);
template <class T, class V>
void _printall(map<T, V> v);
template <class T>
void _printall(multiset<T> v);
template <class T, class V>
void _printall(T a[], V sz) {
  for (V i = 0; i < sz; i++) {
    _printall(a[i]);
    cout << " ";
  }
  cout << endl;
}
template <class T, class V>
void _printall(pair<T, V> p) {
  _printall(p.ff);
  cout << ",";
  _printall(p.ss);
}
template <class T>
void _printall(vector<T> v) {
  for (T i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
template <class T>
void _printall(set<T> v) {
  for (T i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
template <class T>
void _printall(multiset<T> v) {
  for (T i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
template <class T, class V>
void _printall(map<T, V> v) {
  for (auto i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
long long mod = round(pow(10, 9)) + 7;
long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long fe(long long base, long long exp) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = mul(ans, base);
    base = mul(base, base);
    exp >>= 1;
  }
  return ans;
}
long long fact(long long n) {
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
long long modin(long long a) { return fe(a, mod - 2); }
long long nCr(long long a, long long b) {
  if (a < b) return 0;
  return mul(fact(a), mul(modin(fact(b)), modin(fact(a - b))));
}
long long kadane(vector<long long> v) {
  long long currmax = INT_MIN;
  long long global_max = INT_MIN;
  for (int i = 0; i < v.size(); i++) {
    currmax = max(v[i], currmax + v[i]);
    global_max = max(global_max, currmax);
  }
  return global_max;
}
long long INF = 1e18;
void solve() {
  long long a;
  long long b;
  cin >> a;
  cin >> b;
  string s;
  cin >> s;
  long long n = s.size();
  long long ans = 0;
  long long index = 0;
  while (index < n && s[index] == '0') {
    index++;
  }
  long long index2 = n - 1;
  while (index2 >= 0 && s[index2] == '0') {
    index2--;
  }
  for (int i = index; i < index2 + 1; i++) {
    if (s[i] == '1') {
      ans += a;
      while (i < n && s[i] == '1') {
        i++;
      }
    } else {
      long long cnt = 0;
      while (i < n && s[i] == '0') {
        cnt++;
        i++;
      }
      if (cnt * b <= a) {
        ans -= a;
        ans += cnt * b;
      }
    }
    if (i == index2 + 1) {
      break;
    }
    i--;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
