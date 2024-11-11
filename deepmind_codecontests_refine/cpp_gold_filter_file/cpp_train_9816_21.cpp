#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  T res = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    res = (res << 3) + (res << 1) + c - '0';
    c = getchar();
  }
  x = res * f;
}
const long long N = 200000 + 10;
const int mod = 1e9 + 7;
long long n, q, sum[N], tot = 1, fac[22], len;
vector<int> find(long long x) {
  x--;
  vector<int> res, ans;
  for (int i = 1; i <= len; i++) res.push_back(i);
  for (int i = 1; i <= len; i++) {
    long long re = x / fac[len - i];
    ans.push_back(res[re]);
    res.erase(res.begin() + (re));
    x %= fac[len - i];
  }
  return ans;
}
int main() {
  read(n);
  read(q);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + i;
  fac[0] = 1;
  for (int i = 1; i <= 20; i++) fac[i] = fac[i - 1] * i;
  long long L = max(1ll, n - 15);
  len = n - L + 1;
  while (q--) {
    int ty;
    read(ty);
    if (ty == 1) {
      int l, r;
      read(l), read(r);
      if (r < L) {
        printf("%lld\n", sum[r] - sum[l - 1]);
      } else {
        long long ans = 0;
        int st;
        if (l < L) {
          ans += sum[L - 1] - sum[l - 1];
          st = L;
        } else {
          st = l;
        }
        vector<int> pt = find(tot);
        for (int i = st; i <= r; i++) ans += L - 1 + pt[i - L];
        printf("%lld\n", ans);
      }
    } else {
      int x;
      read(x);
      tot += x;
    }
  }
  return 0;
}
