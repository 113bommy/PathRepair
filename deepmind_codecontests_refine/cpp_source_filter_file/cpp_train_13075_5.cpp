#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1005];
char t[1005];
int pos[1005];
int k;
int main() {
  memset(pos, 0, sizeof(pos));
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  scanf("%s", t);
  k = 0;
  int xiao = 1005;
  int da = -1;
  for (int i = 0; i < m - n; i++) {
    int ii = i;
    for (int j = 0; j < n; j++) {
      if (t[ii] == s[j]) {
        pos[i]++;
      }
      da = max(da, pos[i]);
      ii++;
    }
  }
  xiao = n - da;
  printf("%d\n", xiao);
  int mak;
  for (int i = 0; i < m; i++) {
    if (da == pos[i]) {
      mak = i;
      break;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (t[mak] != s[i] && cnt != xiao - 1) {
      printf("%d ", (i + 1));
      cnt++;
    } else if (t[mak] != s[i] && cnt == xiao - 1) {
      printf("%d\n", (i + 1));
      break;
    }
    mak++;
  }
}
