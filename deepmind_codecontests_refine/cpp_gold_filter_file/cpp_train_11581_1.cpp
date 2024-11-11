#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6 + 5;
long long T, n, d[maxn];
char s[maxn], t[maxn];
vector<long long> out;
int main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    long long L = 1, R = n;
    out.clear();
    while (R - L + 1 > 1 && s[L] == s[R]) {
      out.push_back(s[L]);
      L++, R--;
    }
    n = R - L + 1;
    for (int i = 1; i <= R - L + 1; i++) {
      t[i] = s[i + L - 1];
    }
    for (int i = n; i >= 1; i--) {
      t[2 * i] = t[i];
    }
    for (int i = 0; i <= n; i++) {
      t[2 * i + 1] = '#';
    }
    n = 2 * n + 1;
    for (int i = 1; i <= n; i++) d[i] = 1;
    long long p = 0, maxr = 0;
    long long ansid = 0;
    for (int i = 1; i <= n; i++) {
      if (i <= maxr) {
        d[i] = min(d[p + maxr - i], maxr - i + 1);
      }
      while (i - d[i] > 0 && i + d[i] <= n && t[i - d[i]] == t[i + d[i]])
        ++d[i];
      if (i + d[i] - 1 > maxr) {
        p = i - d[i] + 1;
        maxr = i + d[i] - 1;
      }
      if (i - d[i] + 1 == 1 || i + d[i] - 1 == n) {
        if (d[i] >= d[ansid]) ansid = i;
      }
    }
    long long len = (int)(out.size()) - 1;
    for (int i = 0; i <= len; i++) {
      putchar(out[i]);
    }
    L = ansid - d[ansid] + 1, R = ansid + d[ansid] - 1;
    for (int i = L; i <= R; i++) {
      if (t[i] != '#') {
        putchar(t[i]);
      }
    }
    for (int i = len; i >= 0; i--) {
      putchar(out[i]);
    }
    puts("");
  }
  return 0;
}
