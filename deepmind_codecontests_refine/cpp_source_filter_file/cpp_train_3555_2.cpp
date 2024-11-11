#include <bits/stdc++.h>
using namespace std;
int a[333333], b[333333], c[333333], s1[1555555], s2[1555555], s3[1555555],
    s4[1555555], s5[1555555], s6[1555555], cnt, cnt2;
bool f(int x, int y) { return a[x] < a[y]; }
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(c + 1, c + n + 1, f);
  sort(b + 1, b + n + 1);
  int i = 1;
  int j = n;
  while (i <= j) {
    while (i <= n && a[c[i]] == b[i]) i++;
    if (i > n) break;
    if (a[c[i]] > b[i]) {
      puts("NO");
      return 0;
    }
    j = max(j, i + 1);
    while (j <= n && a[c[j]] <= b[j]) j++;
    if (j > n) {
      puts("NO");
      return 0;
    }
    if (i > j) break;
    int t = min(b[i] - a[c[i]], a[c[j]] - b[j]);
    a[c[i]] += t;
    a[c[j]] -= t;
    cnt++;
    s1[cnt] = c[i];
    s2[cnt] = c[j];
    s3[cnt] = t;
  }
  if (cnt > 5 * n) exit(-1);
  puts("YES");
  printf("%d\n", cnt + cnt2);
  for (int i = cnt; i >= 1; i--) {
    printf("%d %d %d\n", s1[i], s2[i], s3[i]);
  }
  for (int i = cnt2; i >= 1; i--) {
    printf("%d %d %d\n", s4[i], s5[i], s6[i]);
  }
}
