#include <bits/stdc++.h>
const int MAXN = 1e6 + 10;
int n, k;
char s[MAXN];
int tot[MAXN];
template <int MOD, int BASE>
struct Hash {
  int h[MAXN], pwr[MAXN], n;
  void init(char *s) {
    n = strlen(s + 1);
    h[0] = 0, pwr[0] = 1;
    for (int i = 1; i <= n; i++) {
      pwr[i] = 1ll * pwr[i - 1] * BASE % MOD;
      h[i] = (1ll * h[i - 1] * BASE + s[i]) % MOD;
    }
  }
  int query(int l, int r) {
    int ans = (h[r] - 1ll * h[l - 1] * pwr[r - l + 1]) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
  }
};
Hash<998244353, 233> sh1;
Hash<1000000007, 137> sh2;
int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  sh1.init(s);
  sh2.init(s);
  for (int i = 1; i * k <= n; i++) {
    bool flag = 1;
    for (int j = i + 1; j <= i * k; j += i) {
      if (sh1.query(j, j + i - 1) != sh1.query(1, i) ||
          sh2.query(j, j + i - 1) != sh2.query(1, i)) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      int l = i * k + 1, r = std::min((k + 1) * i, n), ans = i * k;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (sh1.query(i * k + 1, mid) == sh1.query(1, mid - i * k) &&
            sh2.query(i * k + 1, mid) == sh2.query(1, mid - i * k)) {
          ans = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      tot[i * k]++, tot[ans + 1]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    tot[i] += tot[i - 1];
    if (tot[i])
      putchar('1');
    else
      putchar('0');
  }
  puts("");
}
