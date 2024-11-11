#include <bits/stdc++.h>
using namespace std;
int n, k, l;
const int N = 100;
char s[N], p[N];
char r[N];
bool print(int k) {
  for (int i = 0; i < (int)l; i++) {
    if (r[k + i] != 1 && r[k + i] != s[i]) return false;
    r[k + i] = s[i];
  }
  return true;
}
bool bad(int k) {
  if (k < 0 || k + l > n) return false;
  for (int i = 0; i < (int)l; i++)
    if (r[k + i] == 1 || r[k + i] != s[i]) return false;
  return true;
}
bool go(int x) {
  if (x >= n) return true;
  if (r[x] != 1) return go(x + 1);
  for (int i = 0; i < (int)k; i++) {
    r[x] = 'a' + i;
    bool ok = true;
    for (int j = x - l + 1; j <= x; j++) ok &= !bad(j);
    if (ok && go(x + 1)) return true;
  }
  r[x] = 1;
  return false;
}
int main() {
  scanf("%d %d ", &n, &k);
  scanf("%s ", s);
  scanf("%s ", p);
  l = strlen(s);
  for (int i = 0; i < (int)n; i++) r[i] = 1;
  bool ok = true;
  for (int i = 0; i < (int)n - l + 1; i++)
    if (p[i] == '1') ok &= print(i);
  for (int i = 0; i < (int)n; i++)
    if (p[i] == '0') ok &= !bad(i);
  ok &= go(0);
  if (ok)
    printf("%s\n", r);
  else
    puts("No solution");
  return 0;
}
