#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int INF = 1 << 30;
const double eps = 1e-6;
const int mod = 1000000007;
char s[maxn];
int cnt[26][maxn];
void init() {
  int n = strlen(s + 1);
  for (int c = 0; c < 26; c++)
    for (int i = 1; i <= n; i++) {
      cnt[c][i] = cnt[c][i - 1];
      if ('a' + c == s[i]) cnt[c][i] += 1;
    }
}
int main() {
  scanf("%s", s + 1);
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int C = 0;
    for (int i = 0; i < 26; i++)
      if (cnt[i][r] - cnt[i][l - 1] != 0) C++;
    if (l == r || C >= 3 || s[l] == s[r])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
