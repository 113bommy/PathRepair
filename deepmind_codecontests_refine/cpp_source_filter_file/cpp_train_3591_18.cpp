#include <bits/stdc++.h>
using namespace std;
void out(long long t) { cerr << t; }
void out(int t) { cerr << t; }
void out(string t) { cerr << t; }
void out(char t) { cerr << t; }
void out(double t) { cerr << t; }
template <class T, class V>
void out(pair<T, V> p);
template <class T>
void out(vector<T> v);
template <class T>
void out(set<T> v);
template <class T, class V>
void out(map<T, V> v);
template <class T>
void out(multiset<T> v);
template <class T, class V>
void out(pair<T, V> p) {
  cerr << "{";
  out(p.first);
  cerr << ",";
  out(p.second);
  cerr << "}";
}
template <class T>
void out(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void out(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void out(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void out(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    out(i);
    cerr << " ";
  }
  cerr << "]";
}
vector<long long> sieve(long long n) {
  vector<bool> prime(n + 1, true);
  for (long long p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  vector<long long> v;
  for (long long p = 2; p <= n; p++) {
    if (prime[p]) v.push_back(p);
  }
  return v;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long nCr(int n, int r) {
  long long p = 1, k = 1;
  if (n - r < r) {
    r = n - r;
  }
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else {
    p = 1;
  }
  return p;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long l, r;
  l = m - 1;
  r = n - m;
  ;
  ;
  ;
  ;
  long long ans = l > r ? ((m - 1) < 1 ? m : m - 1) : ((m + 1) > n ? m : m + 1);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
