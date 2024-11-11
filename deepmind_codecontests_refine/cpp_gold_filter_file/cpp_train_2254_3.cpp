#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char s[MAXN];
int p[MAXN];
int cnt[MAXN][10];
int par[10];
void solve() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < 10; i++) {
    par[i] = 0;
    cnt[0][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      for (int j = 0; j < 10; j++) {
        cnt[i][j] = cnt[i - 1][j];
      }
      cnt[i][s[i] - '0']++;
    } else {
      cnt[0][s[0] - '0'] = 1;
    }
  }
  for (int i = n - 1; i >= n / 2; i--) {
    if (s[i] >= '1') {
      for (int ii = s[i] - '0' - 1; ii >= 0; ii--) {
        int odd = 0;
        for (int j = 0; j < 10; j++) {
          par[j] = cnt[i - 1][j];
        }
        par[ii]++;
        for (int j = 0; j < 10; j++) {
          if (par[j] & 1) {
            odd++;
          }
        }
        int rest = n - i - 1;
        if (odd > rest) continue;
        if ((rest - odd) & 1) continue;
        int top = 0;
        for (int j = 0; j < 10; j++) {
          if (par[j] & 1) {
            p[top++] = j;
          }
        }
        int pairs = (rest - odd) / 2;
        for (int j = 0; j < pairs; j++) {
          p[top++] = 9;
          p[top++] = 9;
        }
        s[i] = '0' + ii;
        sort(p, p + top);
        reverse(p, p + top);
        for (int j = i + 1; j < n; j++) {
          s[j] = '0' + p[j - i - 1];
        }
        printf("%s\n", s);
        return;
      }
    }
  }
  for (int i = n / 2 - 1; i >= 0; i--) {
    if (i && s[i] >= '1' || !i && s[i] >= '2') {
      s[i]--;
      int top = 0;
      int odd = 0;
      for (int j = 0; j < 10; j++) {
        par[j] = 0;
      }
      if (i) {
        for (int j = 0; j < 10; j++) {
          par[j] = cnt[i - 1][j];
        }
      }
      par[s[i] - '0']++;
      for (int j = 0; j < 10; j++) {
        if (par[j] & 1) {
          p[top++] = j;
        }
      }
      for (; i + 1 + top < n; top++) {
        p[top] = 9;
      }
      sort(p, p + top);
      reverse(p, p + top);
      for (int j = i + 1; j < n; j++) {
        s[j] = '0' + p[j - i - 1];
      }
      printf("%s\n", s);
      return;
    }
  }
  for (int i = 0; i < n - 2; i++) s[i] = '9';
  s[n - 2] = '\0';
  printf("%s\n", s);
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
