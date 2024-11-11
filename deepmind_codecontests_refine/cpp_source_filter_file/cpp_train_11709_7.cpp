#include <bits/stdc++.h>
using namespace std;
char s[605];
int ve[605];
bitset<2000> getval() {
  bitset<2000> ans;
  scanf("%s", s);
  int m = strlen(s);
  reverse(s, s + m);
  int q = (m - 1) >> 3;
  for (int i = 0; i <= q; i++) ve[i] = 0;
  for (int i = m - 1; i >= 0; i--) (ve[i >> 3] *= 10) += s[i] - '0';
  for (int i = 0; i <= 1999; i++) {
    int x = 0;
    for (int j = q; j >= 0; j--) {
      if (x) ve[j] += 100000000;
      x = ve[j] & 1;
      ve[j] >>= 1;
    }
    ans[i] = x;
    while (~q && ve[q] == 0) q--;
    if (q <= 0) break;
  }
  return ans;
}
bitset<2000> vec[2000];
bitset<2000> rec[2000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    bitset<2000> val = getval();
    bitset<2000> tag;
    tag[i] = 1;
    for (int j = 0; j <= 1999; j++)
      if (val[j]) {
        if (vec[j] == 0) {
          vec[j] = val;
          rec[j] = tag;
          puts("0");
          break;
        } else {
          val ^= vec[j];
          tag ^= rec[j];
        }
      }
    if (val == 0) {
      tag[i] = 0;
      int ans = 0;
      for (int j = 0; j <= 1999; j++)
        if (tag[j]) ans++;
      printf("%d ", ans);
      for (int j = 0; j <= 1999; j++)
        if (tag[j]) printf("%d ", j);
      puts("");
    }
  }
  return 0;
}
