#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 2010000;
set<pair<int, int> > st;
int n, m, x, l, a[N], cdt[N], ct, vis[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < m + 1; i++) {
    scanf("%d%d", &x, &l);
    a[i] = x + l;
    if (cdt[x] == 0 || a[i] > a[cdt[x]]) cdt[x] = i;
  }
  ct = m;
  for (int i = 1; i < n + 2; i++)
    if (cdt[i]) {
      vis[cdt[i]] = 1;
      --ct;
      int l = i, r = a[cdt[i]];
      st.clear();
      for (int j = l; j < r + 1; j++)
        if (cdt[j]) st.insert(make_pair(a[cdt[j]], j));
      while (1) {
        if (st.rbegin()->first == r) break;
        int tl = st.rbegin()->second, tr = st.rbegin()->first;
        vis[cdt[tl]] = 1;
        --ct;
        for (int j = l; j < tl; j++)
          if (cdt[j]) st.erase(make_pair(a[cdt[j]], j));
        for (int j = r + 1; j < tr + 1; j++)
          if (cdt[j]) st.insert(make_pair(a[cdt[j]], j));
        l = tl, r = tr;
      }
      i = r;
    }
  printf("%d\n", ct);
  for (int i = 1; i < m + 1; i++)
    if (!vis[i]) printf("%d ", i);
}
