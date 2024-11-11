#include <bits/stdc++.h>
const int N = 100005;
using namespace std;
char s[N];
int f[N], q[N], c[26];
int main() {
  int m, l, i, j, k;
  scanf("%d", &m);
  scanf("%s", s);
  l = strlen(s);
  s[l] = 'A';
  int h, t;
  for (i = 0; i < 26; i++) {
    int cnt = 0;
    bool ok = true;
    for (j = 0; j <= l; j++) {
      if (cnt >= m) ok = false;
      if (s[j] <= i + 'a')
        cnt = 0;
      else
        cnt++;
      if (s[j] == i + 'a') c[i]++;
    }
    if (cnt >= m) ok = false;
    if (!ok) continue;
    cnt = 0;
    c[i] = 0;
    for (j = 0; j <= l; j++) {
      if (s[j] < i + 'a') {
        if (cnt >= m) {
          int l = j - cnt, r = j - 1;
          h = 0;
          t = 0;
          for (k = l; k <= l + m - 1; k++)
            if (s[k] == i + 'a') {
              f[k] = 1;
              q[t++] = k;
            }
          for (; k < j; k++) {
            if (q[h] <= k - m) h++;
            if (s[k] == i + 'a') {
              f[k] = f[q[h]] + 1;
              while (t > h && f[k] < q[t - 1]) t--;
              q[t++] = k;
            }
          }
          int res = -1;
          for (k = j - 1; k >= j - m; k--)
            if (s[k] == i + 'a' && (res == -1 || f[k] < res)) res = f[k];
          c[i] += res;
        }
        cnt = 0;
      } else
        cnt++;
    }
    break;
  }
  for (i = 0; i < 26; i++)
    for (j = 0; j < c[i]; j++) printf("%c", i + 'a');
  return 0;
}
