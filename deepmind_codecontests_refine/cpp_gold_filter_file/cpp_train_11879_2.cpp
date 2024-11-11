#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - 48;
  return n;
}
const int maxn = 3e5 + 5;
int i, j, n, k, l, r, L, id, f[maxn];
long long ans;
vector<pair<int, int> > a[maxn];
set<pair<int, int> > A;
void ins(int x, int len, int id) {
  if (!len) return;
  a[x].push_back((make_pair(id, len)));
}
int main() {
  n = read(), k = read();
  A.insert((make_pair(1e9 + 5, 0)));
  for (i = 1; i <= n; i++) {
    l = read(), r = read(), id = -1, L = l;
    for (;;) {
      set<pair<int, int> >::iterator it = A.lower_bound((make_pair(l, 0)));
      if (id < 0) id = it->second;
      if (it->first <= r) {
        ins(i, it->first - L, it->second + 1);
        L = it->first, A.erase(it);
        continue;
      }
      ins(i, r - L, it->second + 1);
      break;
    }
    A.insert((make_pair(r, i))), A.insert((make_pair(l, id)));
  }
  l = 0, r = 1e9;
  for (; l <= r;) {
    int mid = (l + r) >> 1, cnt = 0, L = 1;
    memset(f, 0, sizeof(f));
    long long s = 0, S = 0;
    for (i = 1; i <= n; i++) {
      for (j = 0; j < a[i].size(); j++) {
        pair<int, int> now = a[i][j];
        if (now.first <= L)
          f[L] += now.second, s += (long long)(L - now.first) * now.second;
        else
          f[now.first] += now.second;
        f[i + 1] -= now.second;
      }
      for (; f[L] >= mid && L <= i; L++) s += f[L], f[L + 1] += f[L];
      S += s, cnt += L - 1;
      if (cnt > k) break;
    }
    if (cnt > k)
      l = mid + 1;
    else if (cnt == k) {
      ans = S;
      break;
    } else
      r = mid - 1, ans = S + (long long)(k - cnt) * (mid - 1);
  }
  printf("%lld\n", ans);
}
