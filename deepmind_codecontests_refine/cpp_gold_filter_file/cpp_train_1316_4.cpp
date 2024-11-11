#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
template <typename T>
using vec = vector<T>;
using vi = vec<int>;
using vl = vec<ll>;
template <typename T>
using que = queue<T>;
template <typename T>
using deq = deque<T>;
template <typename T>
T id(T b) {
  return b;
};
template <typename T>
void chmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void chmin(T &x, T y) {
  if (x > y) x = y;
}
template <typename S, typename K>
bool contains(S &s, K k) {
  return s.find(k) != s.end();
}
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
constexpr ll TEN(int n) {
  if (n == 0)
    return 1LL;
  else
    return 10LL * TEN(n - 1);
}
const int MAX_C = 100000;
ll n, m, c1, c2, v;
ll l[MAX_C + 2];
ll e[MAX_C + 2];
const ll INF = TEN(12);
int main() {
  fastio();
  cin >> n >> m >> c1 >> c2 >> v;
  for (int i = 1; i <= int(c1); i++) cin >> l[i];
  for (int i = 1; i <= int(c2); i++) cin >> e[i];
  c1 += 2, c2 += 2;
  l[0] = -INF;
  e[0] = -INF;
  l[c1 - 1] = INF;
  e[c2 - 1] = INF;
  sort(l, l + c1);
  sort(e, e + c2);
  int q;
  cin >> q;
  while (q--) {
    ll x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    ll temp = INF;
    if (y1 == y2) {
      temp = abs(x1 - x2);
    }
    auto it = lower_bound(l, l + c1, x1);
    chmin(temp, *it - x1 + abs(y2 - y1) + abs(*it - x2));
    it--;
    chmin(temp, x1 - *it + abs(y2 - y1) + abs(*it - x2));
    it = lower_bound(e, e + c2, x1);
    chmin(temp, *it - x1 + (abs(y2 - y1) + v - 1) / v + abs(*it - x2));
    it--;
    chmin(temp, x1 - *it + (abs(y2 - y1) + v - 1) / v + abs(*it - x2));
    cout << temp << '\n';
  }
  return 0;
}
