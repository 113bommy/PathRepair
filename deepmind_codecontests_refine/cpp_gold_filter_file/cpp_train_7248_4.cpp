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
int n, m, c;
int main() {
  fastio();
  cin >> n >> m >> c;
  vi s(n, 1000000);
  int l = 0, r = n;
  for (int i = 0; i < int(m); i++) {
    int x;
    cin >> x;
    int k;
    if (x <= c / 2) {
      k = upper_bound(s.begin(), s.begin() + l + 1, x) - s.begin();
      chmax(l, k + 1);
    } else {
      k = lower_bound(s.begin() + r, s.end(), x) - s.begin();
      k--;
      chmin(r, k);
    }
    assert(k < n);
    s[k] = x;
    cout << k + 1 << endl;
    if (l >= r) {
      return 0;
    }
  }
  return 0;
}
