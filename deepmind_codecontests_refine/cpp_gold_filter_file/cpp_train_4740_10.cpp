#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30);
int i, n, m, t, k, j;
char a[100], s[100];
bool was[10001];
int main() {
  srand(time(NULL));
  int ans = 0;
  memset((was), (1), sizeof(was));
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    int l, r;
    scanf("%s %d %d\n", s, &l, &r);
    for (j = 0; j < 10000; j++)
      if (was[j]) {
        int b = l, c = r;
        int x = j;
        ans++;
        bool ok = 1;
        for (t = 0; t < 4; t++) {
          a[3 - t] = x % 10 + '0';
          x /= 10;
        }
        for (t = 0; t < 4; t++)
          for (k = t + 1; k < 4; k++)
            if (a[t] == a[k]) ok = 0;
        for (t = 0; t < 4; t++)
          for (k = 0; k < 4; k++)
            if (t != k && a[t] == s[k]) c--;
        for (t = 0; t < 4; t++)
          if (s[t] == a[t]) b--;
        if (b || c) ok = 0;
        if (!ok) was[j] = 0;
      }
  }
  int pos = 0;
  ans = 0;
  for (i = 0; i < 10000; i++) {
    if (was[i]) {
      pos++;
      ans = i;
    }
  }
  if (pos > 1)
    cout << "Need more data";
  else if (pos == 0)
    cout << "Incorrect data";
  else
    printf("%04d", ans);
  return 0;
}
