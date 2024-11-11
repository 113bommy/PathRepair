#include <bits/stdc++.h>
using namespace std;
char s[100050];
char a[100050];
char b[100050];
bool check(int len1, int len2) {
  if (len1 > len2) return true;
  if (len1 < len2) return false;
  int i;
  for (i = 0; i < len1; i++)
    if (a[i] > b[i])
      return true;
    else if (a[i] < b[i])
      return false;
  return true;
}
int main() {
  int now, i, h, j, len, t, ans;
  scanf(" %s", s);
  a[0] = s[0];
  h = now = 1;
  len = strlen(s);
  while (now < len && s[now] == '0') {
    a[h++] = s[now++];
  }
  ans = 1;
  for (i = now; i < len; i++) {
    t = 1;
    b[0] = s[i];
    int k = i + 1;
    while (k < len && s[k] == '0') {
      b[t++] = s[k++];
    }
    if (!check(h, t)) {
      ans = 0;
    }
    for (j = now; j < k; j++) a[h++] = s[j];
    now = k;
    i = k - 1;
    ans++;
  }
  printf("%d\n", ans);
}
