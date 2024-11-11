#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ld = long double;
const int N = 3e5 + 1;
const lli MOD = 998244353;
int n, m;
int ar[N];
lli t[N];
void build(int v, int tl, int tr, bool ok) {
  if (tl == tr) {
    t[v] = ar[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, !ok);
    build(2 * v + 1, tm + 1, tr, !ok);
    if (ok == 1) {
      t[v] = t[2 * v] | t[2 * v + 1];
    } else {
      t[v] = t[2 * v] ^ t[2 * v + 1];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  bool ok = n & 1;
  n = 1 << n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  build(1, 0, n - 1, ok);
  while (m--) {
    int a;
    lli x;
    cin >> a >> x;
    a--;
    t[n + a] = x;
    bool check = 1;
    for (int i = (n + a) / 2; i >= 1; i /= 2) {
      if (check) {
        t[i] = t[2 * i] | t[2 * i + 1];
        check = 0;
      } else {
        t[i] = t[2 * i] ^ t[2 * i + 1];
        check = 1;
      }
    }
    cout << t[1] << '\n';
  }
}
