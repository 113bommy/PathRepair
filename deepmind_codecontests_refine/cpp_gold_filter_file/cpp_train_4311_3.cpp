#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-6;
int main() {
  char s[1005];
  scanf("%s", s);
  int n;
  scanf("%d", &n);
  int len = strlen(s);
  int cnt[26] = {0};
  for (int i = 0; i < len; i++) cnt[s[i] - 'a']++;
  bool found = false;
  for (int res = 1; res <= len; res++) {
    int need = 0;
    int res_cnt[26] = {0};
    for (int k = 0; k < 26; k++)
      need += res_cnt[k] = (int)ceil((double)cnt[k] / res);
    if (need <= n) {
      found = true;
      printf("%d\n", res);
      for (int k = 0; k < 26; k++)
        for (int j = 0; j < res_cnt[k]; j++) putchar(k + 'a');
      for (int i = 0; i < n - need; i++) putchar('z');
      puts("");
      break;
    }
  }
  if (!found) puts("-1");
  return 0;
}
