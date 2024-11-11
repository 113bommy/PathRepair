#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
struct bit {
  ll x[1 << 20];
  int siz;
  void init(int n) {
    for (siz = 1; siz <= n; siz <<= 1)
      ;
  }
  void add(int v, int a) {
    while (v <= siz) {
      x[v] += a;
      v += (v & -v);
    }
  }
  ll sum(int v) {
    ll ret = 0;
    while (v) {
      ret += x[v];
      v -= (v & -v);
    }
    return ret;
  }
  int kth(ll k) {
    int pos = 0;
    for (int i = siz >> 1; i; i >>= 1) {
      if (x[pos + i] < k) {
        pos += i;
        k -= x[i];
      }
    }
    return pos + 1;
  }
};
bit b, b2;
int p[200002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  b.init(n + 1);
  b2.init(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    p[x] = i;
  }
  ll inv = 0;
  for (int i = 1; i <= n; i++) {
    b.add(p[i], 1);
    b2.add(p[i], p[i]);
    inv += (i - b.sum(p[i]));
    int q = b.kth(i / 2 + 1);
    ll tmp = 0;
    tmp += 1LL * q * (i / 2 + 1);
    tmp -= b2.sum(q);
    tmp -= 1LL * (i / 2 + 1) * ((i / 2 + 1) - 1) / 2LL;
    tmp -= 1LL * q * (i - (i / 2 + 1));
    tmp += b2.sum(n) - b2.sum(q);
    tmp -= 1LL * (i - (i / 2 + 1)) * (i - (i / 2 + 1) + 1) / 2LL;
    cout << inv + tmp << ' ';
  }
}
