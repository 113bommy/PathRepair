#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
const int M = 2005;
bitset<M> val, pri;
void init_() {
  static char s[M];
  static int ch[M];
  scanf("%s", s);
  int m = strlen(s) - 1;
  memset(ch, 0, sizeof(ch));
  for (int i = m; i >= 0; i--) (ch[i >> 3] *= 10) += s[m - i] - '0';
  m >>= 3, val = pri = 0;
  for (int i = 0; ~m; i++) {
    val[i] = ch[0] & 1;
    for (int j = m; j >= 0; j--) {
      if (j && (ch[j] & 1)) ch[j - 1] += 100000000;
      ch[j] >>= 1;
    }
    while (~m && !ch[m]) m--;
  }
}
int poi[M], m;
bitset<M> tab[M], idx[M];
void solve(int k) {
  for (int i = N; i >= 0; i--)
    if (val[i]) {
      if (poi[i]) {
        val ^= tab[poi[i]];
        pri ^= idx[poi[i]];
      } else {
        m++;
        poi[i] = k;
        tab[m] = val;
        pri[k] = 1;
        idx[m] = pri;
        puts("0");
        return;
      }
    }
  int tot = 0;
  for (int i = 1; i <= N; i++)
    if (pri[i]) tot++;
  printf("%d ", tot);
  for (int i = 1; i <= N; i++)
    if (pri[i]) printf("%d ", i - 1);
  puts("");
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    init_();
    solve(i);
  }
  return 0;
}
