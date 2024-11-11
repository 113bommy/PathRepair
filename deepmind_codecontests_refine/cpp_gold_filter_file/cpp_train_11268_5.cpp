#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
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
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
const long long mod = 1e9 + 7;
const long long N = 200020;
const long long inf = 1e18;
const long long ninf = -1e18;
long long gcd(long long, long long);
long long modPower(long long, long long, long long);
long long power(long long, long long);
long long modInverse(long long, long long);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long modPower(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = modPower(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long p = power(x, y / 2);
  p = (p * p);
  return (y % 2 == 0) ? p : (x * p);
}
long long modInverse(long long a, long long m) {
  return ((modPower(a, m - 2, m) + mod) % mod);
}
long long modDivide(long long a, long long b, long long m) {
  a = a % m;
  long long inv = modInverse(b, m);
  if (inv == -1)
    return 0;
  else
    return (inv * a) % m;
}
struct comparepq {
  bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.first == b.first) return a.second.first > b.second.first;
    return a.first < b.first;
  }
};
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = (0); i < (n); i++) cin >> arr[i];
  long long presum[n];
  presum[0] = arr[0];
  for (long long i = (1); i < (n); i++) presum[i] = max(arr[i], presum[i - 1]);
  vector<long long> sum;
  for (long long i = (0); i < (60); i++) {
    long long curr = power(2, i);
    if (i == 0)
      sum.push_back(curr);
    else
      sum.push_back(curr + sum[i - 1]);
  }
  long long ans = 0;
  for (long long i = (0); i < (n); i++) {
    long long req = abs(arr[i] - presum[i]);
    if (req > 0) {
      long long id = lower_bound(sum.begin(), sum.end(), req) - sum.begin() + 1;
      ans = max(ans, id);
    }
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  for (long long i = (0); i < (t); i++) {
    solve();
  }
  return 0;
}
