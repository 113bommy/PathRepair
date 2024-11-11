#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n;
char a[1001];
int d[1000];
void solution() {
  scanf("%d\n", &n);
  gets(a);
  d[0] = 1;
  for (int i = 0, _n = (n - 1); i < _n; ++i) {
    if (a[i] == '=')
      d[i + 1] = d[i];
    else if (a[i] == 'L')
      d[i + 1] = min(d[i] - 1, 1);
    else if (a[i] == 'R')
      d[i + 1] = d[i] + 1;
    else
      throw 1;
  }
  for (;;) {
    int k = 0;
    for (int i = 0, _n = (n); i < _n; ++i)
      if (d[i] < d[k]) k = i;
    if (d[k] >= 1) break;
    d[k] = 1;
    for (int i = k - 1; i >= 0; i--) {
      if (a[i] == '=' && d[i] != d[i + 1])
        d[i] = d[i + 1];
      else if (a[i] == 'L' && d[i] <= d[i + 1])
        d[i] = d[i + 1] + 1;
      else
        break;
    }
    for (int i = k; i < n; i++) {
      if (a[i] == '=' && d[i + 1] != d[i])
        d[i + 1] = d[i];
      else if (a[i] == 'R' && d[i + 1] <= d[i])
        d[i + 1] = d[i] + 1;
      else
        break;
    }
  }
  for (int i = 0, _n = (n); i < _n; ++i) printf("%d ", d[i]);
  putchar('\n');
}
int main() {
  solution();
  return 0;
}
