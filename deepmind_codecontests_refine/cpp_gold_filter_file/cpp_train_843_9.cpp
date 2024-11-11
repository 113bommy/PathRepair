#include <bits/stdc++.h>
using namespace std;
char s1[100021], s2[100021];
int nx[100021], ex[100021], nxt[100021];
void getnext() {
  int i = 0, j, po = 1, len = strlen(s2);
  nx[0] = len;
  while (s2[i] == s2[i + 1] && i + 1 < len) i++;
  nx[1] = i;
  for (i = 2; i < len; i++) {
    if (nx[i - po] + i < nx[po] + po)
      nx[i] = nx[i - po];
    else {
      j = nx[po] + po - i;
      if (j < 0) j = 0;
      while (i + j < len && s2[i + j] == s2[j]) j++;
      nx[i] = j;
      po = i;
    }
  }
}
void exkmp() {
  int i = 0, j, po = 0, l1 = strlen(s1), l2 = strlen(s2);
  getnext();
  while (s1[i] == s2[i] && i < l1 && i < l2) i++;
  ex[0] = i;
  for (i = 1; i < l1; i++) {
    if (nx[i - po] + i < po + ex[po])
      ex[i] = nx[i - po];
    else {
      j = ex[po] + po - i;
      if (j < 0) j = 0;
      while (i + j < l1 && j < l2 && s1[i + j] == s2[j]) j++;
      ex[i] = j;
      po = i;
    }
  }
}
void getnxt() {
  int l2 = strlen(s2);
  for (int j, i = 1; i < l2; i++) {
    j = nxt[i];
    while (j && s2[j] != s2[i]) j = nxt[j];
    nxt[i + 1] = s2[j] == s2[i] ? j + 1 : 0;
  }
}
long long sum[100021];
int main() {
  scanf("%s%s", s1, s2);
  exkmp();
  getnxt();
  int l1 = strlen(s1), l2 = strlen(s2);
  long long ans = 1ll * l1 * l2;
  for (int i = 1; i <= l2; i++)
    if (nxt[i]) sum[i - nxt[i]]++;
  for (int i = 1; i <= l2; i++) sum[i] += sum[i - 1];
  for (int i = 1; i < l1; i++) ans -= sum[ex[i]];
  cout << ans;
  return 0;
}
