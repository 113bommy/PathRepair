#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = (1 << 21) + 5;
char inS[21], inT[21];
int s[N], t[N], S[N], T[N], n, m, k, a[N], b[N];
int mis[N], mxt[N];
int bitc(int x) {
  int res = 0;
  for (int i = (0), stOxrj = (k - 1); i <= stOxrj; ++i)
    if ((1 << i) & x) ++res;
  return res;
}
int ans, u, v;
void get() {
  cerr << ans << endl;
  for (int i = (0), stOxrj = ((1 << k) - 1); i <= stOxrj; ++i)
    if (mxt[i] - mis[i] >= m && bitc(i) == ans) {
      u = mis[i], v = mxt[i];
      return;
    }
}
int p[21], q[21];
void cz() {
  for (int i = (0), stOxrj = (k - 1); i <= stOxrj; ++i) p[i] = i;
}
signed main() {
  memset(mis, 0x3f, sizeof(mis));
  memset(mxt, -1, sizeof(mxt));
  n = read(), m = read(), k = read();
  scanf("%s%s", inS, inT);
  for (int i = (0), stOxrj = (k - 1); i <= stOxrj; ++i)
    S[i] = inS[i] - '0', s[n + 1] |= S[i] << i;
  for (int i = (0), stOxrj = (k - 1); i <= stOxrj; ++i)
    T[i] = inT[i] - '0', t[n + 1] |= T[i] << i;
  for (int i = (1), stOxrj = (n); i <= stOxrj; ++i)
    a[i] = read(), b[i] = read();
  cz();
  for (int i = (n), stOxrj = (1); i >= stOxrj; --i) {
    for (int j = (0), stOxrj = (k - 1); j <= stOxrj; ++j) {
      if (p[j] == a[i] - 1)
        p[j] = b[i] - 1;
      else if (p[j] == b[i] - 1)
        p[j] = a[i] - 1;
    }
    for (int j = (0), stOxrj = (k - 1); j <= stOxrj; ++j) s[i] |= S[p[j]] << j;
    for (int j = (0), stOxrj = (k - 1); j <= stOxrj; ++j) t[i] |= T[p[j]] << j;
  }
  for (int i = (1), stOxrj = (n + 1); i <= stOxrj; ++i)
    mis[s[i]] = min(i, mis[s[i]]);
  for (int i = (1), stOxrj = (n + 1); i <= stOxrj; ++i)
    mxt[t[i]] = max(i, mxt[t[i]]);
  for (int i = ((1 << k) - 1), stOxrj = (0); i >= stOxrj; --i)
    for (int j = (0), stOxrj = (k - 1); j <= stOxrj; ++j) {
      mis[i] = min(mis[i], mis[i | (1 << j)]),
      mxt[i] = max(mxt[i], mxt[i | (1 << j)]);
    }
  for (int i = (0), stOxrj = ((1 << k) - 1); i <= stOxrj; ++i)
    if (mxt[i] - mis[i] >= m) ans = max(ans, bitc(i));
  get();
  printf("%d\n", bitc(s[u] ^ t[v] ^ ((1 << k) - 1)));
  printf("%d %d\n", u, v - 1);
  return 0;
}
