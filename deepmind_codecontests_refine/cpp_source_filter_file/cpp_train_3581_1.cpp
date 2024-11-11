#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class T>
void PV(T a, T b) {
  while (a != b) cout << *a++, cout << (a != b ? " " : "\n");
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 3 * 111111;
int n, q;
int d[N];
int p[N];
int v[N];
void add(int first, int t) {
  if (first == 0) return;
  while (first <= n) {
    v[first] += t;
    first += first & (first ^ (first - 1));
  }
}
int sum(int first) {
  int r = 0;
  while (first > 0) {
    r += v[first];
    first -= first & (first ^ (first - 1));
  }
  return r;
}
int main() {
  cin >> n;
  p[0] = 0, p[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) cin >> d[i], p[d[i]] = i;
  for (int i = 1; i <= n; i++)
    if (p[d[i] - 1] > i) add(d[i], 1);
  cin >> q;
  while (q--) {
    int op, l, r, t;
    cin >> op >> l >> r;
    if (op == 1) {
      cout << sum(r) - sum(l - 1) + 1 << endl;
    } else {
      if (d[l] > d[r]) {
        t = p[d[r] - 1];
        if (l < t && t < r) add(d[r], 1);
        t = p[d[r] + 1];
        if (l < t && t < r) add(d[r] + 1, -1);
        t = p[d[l] + 1];
        if (l < t && t < r) add(d[l] + 1, 1);
        t = p[d[l] - 1];
        if (l < t && t < r) add(d[l], -1);
        if (d[l] == d[r] + 1) add(d[l], -1);
      } else if (d[l] < d[r]) {
        t = p[d[l] - 1];
        if (l < t && t < r) add(d[l], -1);
        t = p[d[l] + 1];
        if (l < t && t < r) add(d[l] + 1, 1);
        t = p[d[r] + 1];
        if (l < t && t < r) add(d[r] + 1, -1);
        t = p[d[r] - 1];
        if (l < t && t < r) add(d[r], 1);
        if (d[l] == d[r] - 1) add(d[r], 1);
      }
      swap(d[l], d[r]);
      p[d[l]] = l, p[d[r]] = r;
    }
  }
  return 0;
}
