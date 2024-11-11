#include <bits/stdc++.h>
using namespace std;
char s[100010], buf[200010], is[100010];
int l[200010], n, nxt[100010];
int premn[200010];
void manacher(char *s, int len) {
  buf[0] = '#';
  for (int i = 0; i < len; i++) buf[i * 2 + 1] = '|', buf[i * 2 + 2] = s[i];
  int mid = 0, mxr = 0;
  for (int i = 1; i <= len * 2; i++) {
    if (mxr > i)
      l[i] = min(l[2 * mid - i], mxr - i);
    else
      l[i] = 1;
    while (buf[i + l[i]] == buf[i - l[i]]) l[i]++;
    if (i + l[i] > mxr) mxr = i + l[i], mid = i;
  }
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  manacher(s + 1, n);
  for (int i = 1; i <= n; i++) is[i] = s[i];
  reverse(is + 1, is + n + 1);
  nxt[0] = nxt[1] = 0;
  for (int i = 2; i <= n; i++) {
    int j = nxt[i - 1];
    while (j && is[i] != is[j + 1]) j = nxt[j];
    if (is[i] == is[j + 1]) j++;
    nxt[i] = j;
  }
  int j = 0;
  memset(premn, 0x3f, sizeof(premn));
  premn[0] = 0;
  for (int i = 1; i <= n; i++) {
    while (j && s[i] != is[j + 1]) j = nxt[j];
    if (s[i] == is[j + 1]) j++;
    premn[j] = min(premn[j], i);
  }
  int ans = 0;
  vector<pair<int, int> > Ans;
  for (int i = 1; i <= n; i++) {
    int lmid = l[i * 2];
    int L1 = (i * 2 - lmid + 1), R1 = (i * 2 + lmid - 1);
    if (L1 % 2 == 1)
      L1 = (L1 + 1) / 2;
    else
      L1 = (L1 / 2);
    if (R1 % 2 == 1)
      R1 = (R1 - 1) / 2;
    else
      R1 = (R1 / 2);
    int L = 0, R = min(L1 - 1, n + 1 - R1), ret = 0;
    while (L <= R) {
      int mid = (L + R) >> 1;
      if (premn[mid] <= L1 - 1)
        ret = mid, L = mid + 1;
      else
        R = mid - 1;
    }
    if (ret * 2 + (R1 - L1 + 1) > ans) {
      ans = ret * 2 + (R1 - L1 + 1);
      Ans.clear();
      if (ret == 0)
        Ans.push_back(make_pair(L1, R1 - L1 + 1));
      else {
        Ans.push_back(make_pair(premn[ret] - ret + 1, ret));
        Ans.push_back(make_pair(L1, R1 - L1 + 1));
        Ans.push_back(make_pair(n - ret + 1, ret));
      }
    }
  }
  printf("%d\n", Ans.size());
  for (auto &x : Ans) printf("%d %d\n", x.first, x.second);
  return 0;
}
