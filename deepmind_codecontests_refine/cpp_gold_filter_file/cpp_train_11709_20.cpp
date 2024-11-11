#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int num[N][N], cnt[N], ln[N], mxb[N], st[N], cntans[N], mx[N];
bitset<3000> bn[N], st2[N];
vector<int> ans[N];
char s[N];
inline void mabna(int ind) {
  while (st[ind] < cnt[ind]) {
    int rem = 0;
    for (int i = st[ind]; i < cnt[ind]; i++) {
      num[ind][i] = num[ind][i] + 10 * rem;
      rem = num[ind][i] & 1;
      if (i == cnt[ind] - 1) bn[ind][ln[ind]] = rem;
      num[ind][i] >>= 1;
    }
    ln[ind]++;
    while (st[ind] < cnt[ind] and num[ind][st[ind]] == 0) st[ind]++;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    for (int j = 0; j < len; j++) {
      int val = s[j] - '0';
      num[i][cnt[i]++] = val;
    }
    st2[i][i] = 1;
    mabna(i);
  }
  fill(mx, mx + N, -1);
  mx[ln[0] - 1] = 0;
  printf("0\n");
  for (int i = 1; i < n; i++) {
    bool fl = false;
    for (int j = ln[i] - 1; j >= 0; j--) {
      if (bn[i][j] == 1) {
        if (mx[j] == -1 and !fl) {
          mx[j] = i;
          fl = true;
          mxb[i] = j;
        }
        if (mx[j] != -1 and mx[j] != i) {
          bn[i] ^= bn[mx[j]];
          st2[i] ^= st2[mx[j]];
        }
      }
    }
    for (int j = 0; j < i; j++) {
      if (bn[j][mxb[i]]) {
        bn[j] ^= bn[i];
        st2[j] ^= st2[i];
      }
    }
    bool f = false;
    for (int j = 0; j < ln[i]; j++)
      if (bn[i][j] != 0) f = true;
    if (f) {
      printf("0\n");
      continue;
    }
    int ct = st2[i].count() - 1;
    printf("%d ", ct);
    for (int j = 0; j < i; j++)
      if (st2[i][j]) printf("%d ", j);
    printf("\n");
  }
  return 0;
}
