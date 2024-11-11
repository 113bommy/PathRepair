#include <bits/stdc++.h>
char s[500005];
int cnt[500005];
bool vowel(char s) {
  return s == 'I' || s == 'E' || s == 'A' || s == 'O' || s == 'U' || s == 'Y';
}
int main() {
  std::cin >> s;
  int len = strlen(s);
  int i;
  double ans = 0;
  for (i = 0; i < len; i++)
    if (vowel(s[i])) {
      int l = i + 1;
      int r = len - i;
      if (l > r) std::swap(l, r);
      cnt[l + 1] += l;
      cnt[r + 1] += -l;
      cnt[r + 1] += l + r;
      cnt[l + r] += -(l + r);
      ans += 1;
    }
  for (i = 1; i <= len; i++)
    if (cnt[i]) {
      cnt[i + 1] += cnt[i];
      ans += cnt[i] * 1.0 / i;
    }
  printf("%.6f\n", ans);
  return 0;
}
