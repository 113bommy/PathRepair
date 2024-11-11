#include <bits/stdc++.h>
using namespace std;
const int tt = 1000000007;
int n, m, k, ans, f[30], id[30], lst[30];
char s[1000005];
void Dec(int &x, int y) {
  x -= y;
  if (x < 0) x += tt;
}
void Inc(int &x, int y) {
  x += y;
  if (x >= tt) x -= tt;
}
bool cmp(const int &A, const int &B) { return lst[A] < lst[B]; }
void getf(int c) {
  Dec(ans, f[c]);
  Inc(f[c], ans + 1);
  Inc(ans, f[c]);
}
int main() {
  scanf("%d%d", &n, &k);
  getchar();
  scanf("%s", s + 1);
  m = strlen(s + 1);
  for (int i = (1); i <= (m); i++) getf(s[i] - 'a'), lst[s[i] - 'a'] = i;
  for (int i = (1); i <= (k); i++) id[i] = i;
  sort(id + 1, id + k + 1, cmp);
  for (int i = (1); i <= (n); i++) getf(id[(i - 1) % k + 1]);
  Inc(ans, 1);
  printf("%d\n", ans);
  return 0;
}
