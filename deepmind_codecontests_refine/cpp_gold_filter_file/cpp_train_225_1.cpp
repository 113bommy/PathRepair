#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const ll MODBASE = 1000000007LL;
const int MAXN = 100010;
const int MAXM = 200010;
const int MAXK = 110;
const int MAXQ = 200010;
ll a, b, A, B;
pair<ll, ll> st, fi;
pair<ll, ll> transform(pair<ll, ll> p) {
  return pair<ll, ll>(p.first + p.second, p.first - p.second);
}
pair<ll, ll> findBlock(pair<ll, ll> p) {
  pair<ll, ll> res;
  if (p.first >= 0)
    res.first = p.first / A;
  else
    res.first = p.first / A - (p.first % A != 0);
  if (p.second >= 0)
    res.second = p.second / B;
  else
    res.second = p.second / B - (p.second % B != 0);
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> a >> b >> st.first >> st.second >> fi.first >> fi.second;
  A = a * 2;
  B = b * 2;
  st = transform(st);
  fi = transform(fi);
  pair<ll, ll> g = findBlock(st), h = findBlock(fi);
  cout << max(abs(g.first - h.first), abs(g.second - h.second));
  return 0;
}
