#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int k;
char s[N];
int last[N], pred[N], a[N], t[N], b[N];
int main() {
  scanf("%s%d", s + 1, &k);
  int n = strlen(s + 1);
  if (k > 1ll * n * (n + 1) / 2) {
    puts("No such line.");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    pred[i] = last[s[i]];
    last[s[i]] = i;
  }
  char c = ' ';
  for (char ch = 'a'; ch <= 'z'; ch++) {
    int cnt = 0, j = last[ch];
    while (j > 0) {
      cnt += n - j + 1;
      if (cnt >= k) break;
      j = pred[j];
    }
    if (cnt >= k) {
      putchar(ch);
      c = ch;
      break;
    }
    k -= cnt;
  }
  int m = 0, j = last[c];
  while (j > 0) {
    m++;
    a[m] = j;
    j = pred[j];
  }
  for (int len = 2; len <= n; len++) {
    if (m >= k) break;
    k -= m;
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= m; i++)
      if (a[i] + len - 1 <= n) {
        b[i] = s[a[i] + len - 1];
        pred[i] = last[b[i]];
        last[b[i]] = i;
      } else
        b[i] = ' ';
    c = ' ';
    for (char ch = 'a'; ch <= 'z'; ch++) {
      int cnt = 0;
      j = last[ch];
      while (j > 0) {
        cnt += (n - a[j] - len + 2);
        if (cnt >= k) break;
        j = pred[j];
      }
      if (cnt >= k) {
        putchar(ch);
        c = ch;
        break;
      }
      k -= cnt;
    }
    int mm = 0;
    for (int i = 1; i <= m; i++)
      if (b[i] == c) {
        mm++;
        t[mm] = i;
      }
    m = mm;
    for (int i = 1; i <= m; i++) a[i] = t[i];
  }
  return 0;
}
