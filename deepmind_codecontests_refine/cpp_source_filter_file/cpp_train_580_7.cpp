#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e3 + 5, mo = 1e9 + 7;
map<int, int> mp, czy;
multiset<int> tr[N];
multiset<int>::iterator it;
int pp[N], a[N], n, T, A, B, S, d, rem, ka, ts, prt[N], x[N], y[N], i;
int exgcd(int a, int b, int &x, int &y) {
  if (!b) return x = 1, y = 0, a;
  int ret = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
}
int main() {
  scanf("%d %d", &T, &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i != 1) y[i] = (y[i - 1] + a[i]) % T;
    if (!mp[y[i]]) mp[y[i]] = i, pp[i] = 1;
    S = (S + a[i]) % T;
  }
  d = exgcd(S, T, A, B), S /= d, T /= d, A %= T;
  if (A < 0) A += T;
  for (i = 2; i <= n; i++)
    if (pp[i]) {
      ka = y[i] % d;
      if (!czy[ka]) czy[ka] = ++ts;
      rem = y[i] - ka, ka = czy[ka], rem /= d;
      x[i] = 1ll * A * rem % T;
      tr[ka].insert(x[i]);
    }
  for (i = 1; i <= n; i++)
    if (pp[i]) {
      ka = czy[y[i] % d];
      it = tr[ka].find(x[i]), it++;
      prt[i] = -x[i];
      if (it == tr[ka].end()) prt[i] += T, it = tr[ka].begin();
      prt[i] += *it;
    }
  for (i = 1; i <= n; i++) printf("%d ", prt[i]);
}
