#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[N], q[N], nxt[N];
map<int, int> mp;
set<int> S;
bool check(int x) {
  for (; x; x /= 10)
    if (x % 10 != 4 && x % 10 != 7) return 0;
  return 1;
}
int main() {
  q[++*q] = 0;
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (check(a[i])) q[++*q] = i;
  long long ans = 1ull * (n + 2) * (n + 1) / 2 * (n) / 3 * (n - 1) / 4;
  for (int i = (int)(*q); i >= (int)(1); i--)
    nxt[i] = mp[a[q[i]]], mp[a[q[i]]] = i;
  for (int i = (int)(2); i <= (int)((*q) - 1); i++) {
    S.clear();
    S.insert(q[i]);
    S.insert(n + 1);
    long long cur = 0, L = q[i + 1] - q[i];
    for (int j = (int)(i); j >= (int)(2); j--) {
      for (int k = nxt[j]; k >= i; k = nxt[k]) {
        set<int>::iterator pre, nxt;
        pre = nxt = S.insert(q[k]).first;
        int pr = *(--pre), nx = *(++nxt);
        if (pr != q[i])
          cur += 1ll * L * (q[k] - pr) * (nx - q[k]);
        else
          cur +=
              (1ll * L * (L + 1) / 2 + 1ll * L * (q[k] - pr - L)) * (nx - q[k]);
      }
      ans -= 1ll * cur * (q[j] - q[j - 1]);
    }
  }
  printf("%lld\n", ans);
}
