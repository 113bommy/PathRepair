#include <bits/stdc++.h>
using namespace std;
const int N = 5000100;
char s[2 * N], ans[N], res[N], tmp[N];
int b[2 * N], t[2 * N], ne[N], fail[N], p[N], can[N], is[500],
    cnt = 0, cnt2 = 0, n, m, tot = 0;
void upd() {
  for (int i = 1; i <= n; i++)
    if (tmp[i] != res[i]) {
      if (tmp[i] < res[i])
        for (int j = 1; j <= n; j++) res[j] = tmp[j];
      break;
    }
}
int get(int pos) { return n - b[n - pos + 1] + 1; }
bool cmp() {
  int i;
  for (i = 1; i <= n; i++)
    if (s[i] < s[n - i + 1])
      return 1;
    else if (s[i] > s[n - i + 1])
      return 0;
  return 0;
}
void duval() {
  int i, j, k, l, nw;
  for (i = 1; i <= n;) {
    j = i;
    k = i + 1;
    while ((k <= n) && (s[j] <= s[k])) {
      if (s[j] == s[k])
        j++, k++;
      else
        j = i, k++;
    }
    nw = i;
    while (i <= j) {
      for (l = 1; l <= k - j; l++) t[l + i - 1] = i, b[l + i - 1] = nw;
      i += k - j;
    }
  }
}
void ycl() {
  int i, j, k, c, len;
  ne[1] = 0;
  j = 0;
  for (i = 2; i <= n; i++) {
    while ((j) && (s[j + 1] != s[i])) j = ne[j];
    if (s[j + 1] == s[i]) j++;
    ne[i] = j;
  }
  fail[1] = n;
  c = 0;
  len = 0;
  for (i = 2; i <= n; i++)
    if ((fail[i - c + 1] + i - c >= len) || (i >= c + len)) {
      if (i >= c + len)
        len = 0;
      else
        len += c - i;
      c = i;
      while ((c + len <= n) && (s[n - (len + 1) + 1] == s[n - (c + len) + 1]))
        len++;
      fail[i] = len;
    } else
      fail[i] = fail[i - c + 1];
  c = 0;
  len = 0;
  for (i = 1; i <= n; i++)
    if ((fail[i - c + 1] + i - c >= len) || (i >= c + len)) {
      if (i >= c + len)
        len = 0;
      else
        len += c - i;
      c = i;
      while ((c + len <= n) && (s[c + len] == s[n - (len + 1) + 1])) len++;
      p[i] = len;
    } else
      p[i] = fail[i - c + 1];
}
void work1() {
  int i, mn;
  ycl();
  mn = 1;
  for (i = 2; i < n; i++) {
    if (p[mn + 1] < i - mn) {
      if (s[mn + 1 + p[mn + 1]] < s[n - p[mn + 1]]) mn = i;
    } else if (fail[i - mn + 1] < n - i) {
      if (s[n - (i - mn) - fail[i - mn + 1]] > s[n - fail[i - mn + 1]]) mn = i;
    }
  }
  for (i = 1; i <= mn; i++) tmp[i] = s[i];
  for (i = n; i > mn; i--) tmp[mn + n - i + 1] = s[i];
  upd();
}
void work2() {
  int i, nw, pos, j;
  cnt = 0;
  can[++cnt] = get(1);
  nw = can[cnt];
  for (nw++; nw <= n; nw++) {
    pos = get(nw);
    nw = pos;
    if (ne[nw] >= can[cnt]) can[++cnt] = nw;
  }
  cnt2 = 0;
  for (i = cnt; i; i = j) {
    is[++cnt2] = can[i];
    j = i - 1;
    while ((j) && (2 * can[j] > can[i])) j--;
  }
  pos = cnt2;
  for (i = cnt2 - 1; i; i--) {
    for (j = is[i] - is[pos]; j; j--)
      if (s[j] != s[is[i] - j + 1]) {
        if (s[j] < s[is[i] - j + 1]) pos = i;
        break;
      }
  }
  for (i = 1; i <= is[pos]; i++) tmp[i] = s[is[pos] - i + 1];
  for (i = is[pos] + 1; i <= n; i++) tmp[i] = s[i];
  upd();
}
void work3() {
  int i, j;
  reverse(s + 1, s + n + 1);
  for (i = n + 1; i <= 2 * n; i++) s[i] = s[i - n];
  s[2 * n + 1] = 'z' + 1;
  n = 2 * n + 1;
  duval();
  n >>= 1;
  for (i = b[2 * n + 1], j = 0; i <= n; i++) tmp[++j] = s[i];
  for (i = 1; i < b[2 * n + 1]; i++) tmp[++j] = s[i];
  upd();
}
int main() {
  int i, j, k;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &m);
  reverse(s + 1, s + n + 1);
  duval();
  reverse(s + 1, s + n + 1);
  for (i = 1; m > 2;) {
    j = get(i);
    m--;
    reverse(s + i, s + j + 1);
    if (j == n) {
      for (i = 1; i <= n; i++) printf("%c", s[i]);
      printf("\n");
      return 0;
    }
    if ((t[n - i + 1] == n - i + 1) && (t[n - j] == n - j)) m++;
    i = j + 1;
  }
  for (j = 1; j < i; j++) ans[j] = s[j];
  tot = i - 1;
  for (i = tot + 1; i <= n; i++) s[i - tot] = s[i];
  n -= tot;
  if (cmp())
    for (i = 1; i <= n; i++) res[i] = s[i];
  else
    for (i = 1; i <= n; i++) res[i] = s[n - i + 1];
  if (m == 1) {
    for (i = 1; i <= tot; i++) printf("%c", ans[i]);
    for (i = 1; i <= n; i++) printf("%c", res[i]);
    printf("\n");
    return 0;
  }
  work1();
  work2();
  work3();
  for (i = 1; i <= tot; i++) printf("%c", ans[i]);
  for (i = 1; i <= n; i++) printf("%c", res[i]);
  printf("\n");
  return 0;
}
