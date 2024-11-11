#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 46;
const int mod = 1e9 + 7;
const long long INF = 2e18;
const int inf = 2e9;
int son[N][2], sz, cnt[N];
long long a[N];
void add(long long val) {
  int v = 0;
  for (int i = 40; i >= 0; --i) {
    bool u = 0;
    if ((1ll << i) & val) {
      u = 1;
    }
    if (!son[v][u]) {
      son[v][u] = ++sz;
    }
    v = son[v][u];
    cnt[v]++;
  }
}
void del(long long val) {
  int v = 0;
  for (int i = 40; i >= 0; --i) {
    bool u = 0;
    if ((1ll << i) & val) {
      u = 1;
    }
    cnt[son[v][u]]--;
    int go = son[v][u];
    if (!cnt[son[v][u]]) son[v][u] = 0;
    v = go;
  }
}
long long get(long long val) {
  int v = 0;
  long long res = 0;
  for (int i = 40; i >= 0; --i) {
    bool u = 0;
    if ((1ll << i) & val) {
      u = 1;
    }
    if (son[v][u ^ 1]) {
      res |= (1ll << i);
      v = son[v][u ^ 1];
    } else {
      v = son[v][u];
    }
  }
  return res;
}
long long suff[N], pref;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n + 1; i >= 1; --i) {
    suff[i] = suff[i + 1] ^ a[i];
    add(suff[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    pref ^= a[i];
    del(suff[i]);
    ans = max(ans, get(pref));
  }
  cout << ans;
}
