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
int main() {
  fastio();
  int n, x;
  cin >> n >> x;
  if (n == 1) {
    cout << "YES\n";
    cout << x << endl;
    return 0;
  }
  if (n == 2) {
    if (x == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << 0 << " " << x << endl;
    }
    return 0;
  }
  cout << "YES\n";
  int a = 0;
  for (int i = 0; i < int(n - 3); i++) {
    cout << i << " ";
    a ^= i;
    x ^= i;
  }
  if ((x ^ (n - 3)) == 0) {
    cout << (n - 3) << " ";
    a ^= (n - 3);
    x ^= (n - 3);
  } else {
    cout << (n - 2) << " ";
    a ^= (n - 2);
    x ^= (n - 2);
  }
  int mask = 1 << 18;
  cout << mask << " " << (mask ^ x) << endl;
  return 0;
}
