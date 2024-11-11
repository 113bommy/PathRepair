#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void doin() {
  cin.tie();
  cout.tie();
  ios::sync_with_stdio(0);
}
template <typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
void getv(T& i) {
  cin >> i;
}
template <typename T, typename... Ns>
void getv(vector<T>& v, int n, Ns... ns) {
  v.resize(n);
  for (auto& i : v) getv(i, ns...);
}
template <typename T>
void getv1(T& i) {
  cin >> i;
}
template <typename T, typename... Ns>
void getv1(vector<T>& v, int n, Ns... ns) {
  v.resize(n + 1);
  for (int i = 1; i <= n; i++) getv(v[i], ns...);
}
inline void getch(char& x) {
  while (x = getchar_unlocked(), x < 33) {
    ;
  }
}
inline void getstr(string& str) {
  str.clear();
  char cur;
  while (cur = getchar_unlocked(), cur < 33) {
    ;
  }
  while (cur > 32) {
    str += cur;
    cur = getchar_unlocked();
  }
}
template <typename T>
inline bool sc(T& num) {
  bool neg = 0;
  int c;
  num = 0;
  while (c = getchar_unlocked(), c < 33) {
    if (c == EOF) return false;
  }
  if (c == '-') {
    neg = 1;
    c = getchar_unlocked();
  }
  for (; c > 47; c = getchar_unlocked()) num = num * 10 + c - 48;
  if (neg) num *= -1;
  return true;
}
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long c, hr, wr, hb, wb;
long long ans = 0;
set<int> a;
void A() {
  long long cur = (c / wr) * hr, left = c % wr, t;
  while (cur >= 0 && a.insert(left % wb).second) {
    ans = max(ans, (t = cur + (left / wb) * hb));
    cur -= hr;
    left += wr;
  }
}
void B() {
  long long cur = 0, left = c, t;
  while (left >= 0 && a.insert(left % wr).second) {
    ans = max(ans, (t = cur + (left / wr) * hr));
    if ((t * 11) < 10 * ans) break;
    cur += hb;
    left -= wb;
  }
}
int main() {
  doin();
  cin >> c >> hr >> hb >> wr >> wb;
  float rr = ((float)hr) / (float)wr;
  float rb = ((float)hb) / (float)wb;
  if (rr < rb) swap(hr, hb), swap(wr, wb);
  if (wr * 3 < wb)
    B();
  else
    A();
  cout << ans;
}
