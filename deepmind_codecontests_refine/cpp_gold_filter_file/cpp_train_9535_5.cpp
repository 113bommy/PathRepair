#include <bits/stdc++.h>
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const int inf = mod;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void in(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A &x, B &y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &xx) {
  in(x);
  in(y);
  in(z);
  in(xx);
}
template <class T>
void upd(T &a, T b) {
  a = max(a, b);
}
const int maxn = 300010;
int n;
int a[maxn];
bool ava[maxn];
int ans[maxn];
int main() {
  int n;
  cin >> n;
  for (long long i = 1; i < n + 1; i++) {
    in(a[i]);
    ans[1] = max(ans[1], a[i]);
  }
  if (n <= 2) {
    for (long long i = 0; i < n; i++) cout << ans[1] << ' ';
  } else {
    vector<pair<int, int> > v;
    for (long long i = 1; i < n + 1; i++) v.push_back(make_pair(a[i], i));
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (auto i : v) {
      ava[i.second] = 1;
      if (i.second == 1) {
        upd(ans[2], i.first);
        int l, r;
        if (ava[i.second + 1]) {
          l = i.second;
          r = n - (i.second + 1);
          upd(ans[min(l, r) * 2 + 3], i.first);
        }
      } else if (i.second == n) {
        upd(ans[2], i.first);
        int l, r;
        if (ava[i.second - 1]) {
          l = i.second - 3;
          r = n - (i.second);
          upd(ans[min(l, r) * 2 + 3], i.first);
        }
      } else {
        int l = i.second - 1, r = n - i.second - 1;
        upd(ans[min(l, r) * 2 + 2], i.first);
        l = i.second - 2, r = n - i.second;
        upd(ans[min(l, r) * 2 + 2], i.first);
        if (ava[i.second + 1] || ava[i.second - 1]) {
          l = i.second - 2;
          r = n - (i.second + 1);
          upd(ans[min(l, r) * 2 + 3], i.first);
        }
        if (ava[i.second + 1]) {
          l = i.second - 1;
          r = n - (i.second + 1);
          upd(ans[min(l, r) * 2 + 3], i.first);
        }
        if (ava[i.second - 1]) {
          l = i.second - 3;
          r = n - (i.second);
          upd(ans[min(l, r) * 2 + 3], i.first);
        }
      }
    }
    for (long long i = n - 2; i >= 1; i--) upd(ans[i], ans[i + 2]);
    for (long long i = n; i >= 1; i--) printf("%d ", ans[i]);
  }
  return 0;
}
