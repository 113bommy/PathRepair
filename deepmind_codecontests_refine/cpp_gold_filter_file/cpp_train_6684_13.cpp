#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int MaxN = (int)2e5;
long long Numin, Pin, hundred, n, q, Now, p[MaxN + 5], sm[MaxN + 5],
    ml[MaxN + 5], ans;
char Ci;
bool ck[MaxN + 5];
set<int> st;
set<int>::iterator lst, nxt;
long long Read() {
  Numin = 0, Pin = 1;
  Ci = 0;
  while (Ci < '0' || Ci > '9') {
    if (Ci == '-') Pin = -1;
    Ci = getchar();
  }
  while (Ci >= '0' && Ci <= '9') {
    Numin = Numin * 10 + Ci - '0';
    Ci = getchar();
  }
  return Numin * Pin;
}
long long ksm(long long ds, long long zs) {
  long long cnt = 1;
  while (zs) {
    if (zs & 1) {
      cnt = cnt * ds % mod;
      zs--;
    } else {
      zs /= 2;
      ds = ds * ds % mod;
    }
  }
  return cnt;
}
long long Calc(long long fr, long long to) {
  return (ml[fr - 1] + (sm[to - 2] - sm[fr - 1] + mod) % mod) % mod *
         ksm(ml[to - 1], mod - 2) % mod;
}
int main() {
  n = Read();
  q = Read();
  hundred = ksm(100, mod - 2);
  ml[0] = 1;
  for (int i = 1; i <= n; i++) {
    Now = Read();
    p[i] = Now * hundred % mod;
    ml[i] = ml[i - 1] * p[i] % mod;
    sm[i] = (sm[i - 1] + ml[i]) % mod;
  }
  st.insert(1);
  st.insert(n + 1);
  ans = (1 +
         ((sm[n - 1] - sm[0] + mod) % mod * ksm(ml[0], mod - 2) % mod) % mod) %
        mod * ksm(ml[n], mod - 2) % mod;
  for (int i = 1; i <= q; i++) {
    Now = Read();
    if (ck[Now]) {
      ck[Now] = false;
      lst = st.lower_bound(Now);
      lst--;
      nxt = st.upper_bound(Now);
      st.erase(Now);
      ans = (ans - Calc((*lst), Now) - Calc(Now, (*nxt)) +
             Calc((*lst), (*nxt)) + mod + mod) %
            mod;
    } else {
      ck[Now] = true;
      lst = st.lower_bound(Now);
      lst--;
      nxt = st.upper_bound(Now);
      st.insert(Now);
      ans = (ans + Calc((*lst), Now) + Calc(Now, (*nxt)) -
             Calc((*lst), (*nxt)) + mod) %
            mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
