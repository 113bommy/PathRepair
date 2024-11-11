#include <bits/stdc++.h>
using namespace std;
char s[1010][1010];
int cnt[1010][1010];
long long cntf[26][1010][1010];
long long cntt[1010][1010];
struct _ {
  int x1, y1, x2, y2;
  char ch;
} a[300010];
inline long long ff(int x1, int y1, int x2, int y2) {
  return cntt[x2][y2] - cntt[x1 - 1][y2] - cntt[x2][y1 - 1] +
         cntt[x1 - 1][y1 - 1];
}
inline long long gg(int x1, int y1, int x2, int y2, char ch) {
  long long ans = 0;
  ch -= 'a';
  for (int i = 0; i < 26; i++) {
    ans += abs(ch - i) * (cntf[i][x2][y2] - cntf[i][x1 - 1][y2] -
                          cntf[i][x2][y1 - 1] + cntf[i][x1 - 1][y1 - 1]);
  }
  return ans;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int i, j;
  for (i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  int x1, y1, x2, y2;
  char ch[5];
  for (i = 0; i < k; i++) {
    scanf("%d%d%d%d%s", &x1, &y1, &x2, &y2, &ch);
    a[i] = (_){x1, y1, x2, y2, ch[0]};
    cnt[x1 - 1][y1 - 1]++;
    cnt[x1 - 1][y2]--;
    cnt[x2][y1 - 1]--;
    cnt[x2][y2]++;
    cntf[ch[0] - 'a'][x1 - 1][y1 - 1]++;
    cntf[ch[0] - 'a'][x1 - 1][y2]--;
    cntf[ch[0] - 'a'][x2][y1 - 1]--;
    cntf[ch[0] - 'a'][x2][y2]++;
  }
  for (i = n; i >= 1; i--) {
    for (j = m; j >= 1; j--) {
      cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
    }
  }
  for (int k = 0; k < 26; k++) {
    for (i = n; i >= 1; i--) {
      for (j = m; j >= 1; j--) {
        cntf[k][i][j] +=
            cntf[k][i + 1][j] + cntf[k][i][j + 1] - cntf[k][i + 1][j + 1];
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cnt[i][j] = k - cnt[i][j];
      cntf[s[i][j] - 'a'][i][j] += cnt[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      for (int k = 'a'; k <= 'z'; k++) {
        cntt[i][j] += abs(k - s[i][j]) * cntf[k - 'a'][i][j];
        cntf[k - 'a'][i][j] += cntf[k - 'a'][i][j - 1] +
                               cntf[k - 'a'][i - 1][j] -
                               cntf[k - 'a'][i - 1][j - 1];
      }
      cntt[i][j] += cntt[i][j - 1] + cntt[i - 1][j] - cntt[i - 1][j - 1];
    }
  }
  long long ans = 998244353998244347;
  long long tmp;
  for (i = 0; i < k; i++) {
    tmp = cntt[n][m];
    tmp -= ff(a[i].x1, a[i].y1, a[i].x2, a[i].y2);
    tmp += gg(a[i].x1, a[i].y1, a[i].x2, a[i].y2, a[i].ch);
    ans = min(ans, tmp);
  }
  printf("%lld\n", ans);
  return 0;
}
