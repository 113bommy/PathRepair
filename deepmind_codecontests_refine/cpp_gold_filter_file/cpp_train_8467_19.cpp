#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
const int MOD2 = 998244353;
const int INF = 1 << 30;
const ll INF2 = (ll)1 << 60;
void scan(int& a) { scanf("%d", &a); }
void scan(long long& a) { scanf("%lld", &a); }
template <class T, class L>
void scan(pair<T, L>& p) {
  scan(p.first);
  scan(p.second);
}
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& vec) {
  for (auto&& it : vec) scan(it);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print(const int& a) { printf("%d", a); }
void print(const long long& a) { printf("%lld", a); }
void print(const double& a) { printf("%.15lf", a); }
template <class T, class L>
void print(const pair<T, L>& p) {
  print(p.first);
  putchar(' ');
  print(p.second);
}
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& vec) {
  if (vec.empty()) return;
  print(vec[0]);
  for (auto it = vec.begin(); ++it != vec.end();) {
    putchar(' ');
    print(*it);
  }
}
void out() { putchar('\n'); }
template <class T>
void out(const T& t) {
  print(t);
  putchar('\n');
}
template <class Head, class... Tail>
void out(const Head& head, const Tail&... tail) {
  print(head);
  putchar(' ');
  out(tail...);
}
template <class T>
void dprint(const T& a) {
  cerr << a;
}
template <class T>
void dprint(const vector<T>& vec) {
  if (vec.empty()) return;
  cerr << vec[0];
  for (auto it = vec.begin(); ++it != vec.end();) {
    cerr << " " << *it;
  }
}
void debug() { cerr << endl; }
template <class T>
void debug(const T& t) {
  dprint(t);
  cerr << endl;
}
template <class Head, class... Tail>
void debug(const Head& head, const Tail&... tail) {
  dprint(head);
  cerr << " ";
  debug(tail...);
}
ll intpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
ll modpow(ll a, ll b, ll p) {
  ll ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= p;
    (a *= a) %= p;
    b /= 2;
  }
  return ans;
}
ll updivide(ll a, ll b) {
  if (a % b == 0)
    return a / b;
  else
    return (a / b) + 1;
}
template <class T>
void chmax(T& a, const T b) {
  if (b > a) a = b;
}
template <class T>
void chmin(T& a, const T b) {
  if (b < a) a = b;
}
int main() {
  ll n;
  in(n);
  if (n == 0) {
    out(0, 0, 0);
    return 0;
  }
  vector<ll> vec(50, 0);
  vec[0] = 0;
  vec[1] = 1;
  for (int i = 2; i < 50; i++) {
    vec[i] = vec[i - 1] + vec[i - 2];
    if (vec[i] == n) {
      out(vec[i - 1], vec[i - 2], 0);
      return 0;
    }
  }
}
