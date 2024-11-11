#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
char s[N];
int n;
int a[N];
int b[N];
const int S = 200;
long long ksm() {
  long long ans = 0;
  for (int k = (int)(1); k <= (int)(S); k++) {
    for (int i = (int)(0); i <= (int)(n); i++) b[i] = k * a[i] - i;
    sort(b, b + 1 + n);
    for (int i = 0; i <= n; i++) {
      int j = i;
      while (j < n && b[j + 1] == b[i]) ++j;
      ans += (j - i + 1) * 1ll * (j - i) / 2;
      i = j;
    }
  }
  return ans;
}
int c[N];
int t;
long long ck(int lp, int rp, int i) {
  if (lp > rp) swap(lp, rp);
  if (i <= min(lp, rp)) return i + 1;
  if (i > lp && i <= rp) {
    return lp + 1;
  } else {
    return max(0, lp - (i - rp) + 1);
  }
}
long long calc(int d) {
  long long res = 0;
  for (int i = (int)(d); i <= (int)(t); i++) {
    int ml = c[i] - c[i - d + 1] + 1;
    int rp = c[i + 1] - 1 - c[i];
    int lp = c[i - d + 1] - c[i - d] - 1;
    for (int i = (int)(0); i <= (int)(lp + rp); i++)
      if ((i + ml) % d == 0)
        if (i + ml > d * S) {
          res += ck(lp, rp, i);
        }
  }
  return res;
}
long long kbg() {
  long long ans = 0;
  t = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (s[i] == 1) c[++t] = i;
  c[t + 1] = n + 1;
  for (int i = (int)(1); i <= (int)(n / max(S, 1)); i++) {
    ans += calc(i);
  }
  return ans;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = (int)(1); i <= (int)(n); i++) s[i] = s[i] - '0';
  for (int i = (int)(1); i <= (int)(n); i++) a[i] = a[i - 1] + s[i];
  printf("%lld\n", ksm() + kbg());
  return 0;
}
