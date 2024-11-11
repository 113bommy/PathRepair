#include <bits/stdc++.h>
using namespace std;
int n, c, a[1000010], b[1000010], r[1000010], t;
int cnt, tot, k, m, sum;
bool ok;
void make_r() {
  int len = min(tot, cnt), i, st, ed;
  for (i = 0; i < len; i++)
    if (b[i] != a[i]) break;
  if (i == len) {
    if (tot > cnt) ok = 1;
    return;
  }
  m++;
  if (b[i] < a[i]) {
    r[0]++;
    r[c - a[i] + 1]--;
    r[c - b[i] + 1]++;
    r[c]--;
  } else {
    r[c - b[i] + 1]++;
    r[c - a[i] + 1]--;
  }
}
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; j++) scanf("%d", a + j);
    ok = 0;
    if (i) make_r();
    if (ok) {
      puts("-1");
      return 0;
    }
    for (int j = 0; j < cnt; j++) b[j] = a[j];
    tot = cnt;
  }
  for (k = 0; k < c; k++) {
    sum += r[k];
    if (sum == m) break;
  }
  if (k >= c)
    puts("-1");
  else
    printf("%d\n", k);
  return 0;
}
