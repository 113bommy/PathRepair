#include <bits/stdc++.h>
using namespace std;
long long n, sz_bor;
const long long MAXN = (long long)1e5 + 10, LOG = 50;
long long a[MAXN], pref[MAXN], suf[MAXN], bor[2][MAXN * LOG];
void add(long long x) {
  long long root = 0;
  for (long long i = LOG - 1; i >= 0; --i) {
    long long b = (x >> i) & 1;
    if (bor[b][root] == 0) bor[b][root] = ++sz_bor;
    root = bor[b][root];
  }
}
long long search_bor(long long x) {
  long long root = 0, ans = 0;
  for (long long i = LOG - 1; i >= 0; --i) {
    long long b = ((x >> i) & 1);
    if (bor[1 - b][root] > 0) {
      root = bor[1 - b][root];
      ans = ((ans << 1) | 1);
    } else {
      root = bor[b][root];
      ans <<= 1;
    }
  }
  return (x ^ ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = (pref[i - 1] ^ a[i]);
  }
  for (long long i = n; i > 0; --i) suf[i] = (suf[i + 1] ^ a[i]);
  long long mx = 1;
  for (long long i = n; i >= 0; --i) {
    add(suf[i + 1]);
    mx = max(mx, pref[i] ^ search_bor(pref[i]));
  }
  cout << mx;
  return 0;
}
