#include <bits/stdc++.h>
const int N = 100001;
long long o, u, n, m, k, x, s[N], S[N], c, h, t;
int main() {
  scanf("%lld%lld%lld", &n, &k, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    if (!c || s[c] != x)
      s[++c] = x, S[c] = 1;
    else
      S[c]++;
    if (S[c] == k) c--;
  }
  for (int i = 1; i <= c; i++) u += S[i];
  h = 1, t = c;
  while (h < t && s[h] == s[t]) {
    if ((S[h] + S[t]) % k == 0)
      h++, t--;
    else {
      S[h] = (S[h] + S[t]) % k, S[t] = 0;
      break;
    }
  }
  if (h < t) {
    for (int i = h; i <= t; i++) o += S[i];
    o = o * (m - 1) + u;
  } else
    o = ((S[h] * m) % k == 0 ? 0
                             : (u + S[h] * (m - 1) - S[h] * m + S[h] * m % k));
  printf("%lld\n", o);
  return 0;
}
