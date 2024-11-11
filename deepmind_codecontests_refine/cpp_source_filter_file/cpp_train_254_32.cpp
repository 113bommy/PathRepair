#include <bits/stdc++.h>
using namespace std;
char s[(1 << 17)];
int n, k, a[(1 << 17)];
vector<int> v[(1 << 17)];
int trans(char* s) {
  int l = strlen(s), res = 0;
  int st = s[0] == '-';
  for (int i = st; i < l; i++) res = res * 10 + s[i] - 48;
  return st ? -res : res;
}
int solve(int l, int r, int st, int ed) {
  vector<int> vt;
  if (l > r) return ed - st >= -1;
  if (st > ed) return 0;
  if (ed - st < (r - l) / k) return 0;
  int cnt = (r - l) / k + 1;
  if (st >= 0) {
    for (int i = 0; i < cnt; i++) vt.push_back(st + i);
  } else if (ed < 0) {
    for (int i = cnt - 1; i >= 0; i--) vt.push_back(ed - i);
  } else {
    vt.push_back(0);
    for (int x = -1, y = 1, i = 1; i < cnt; i++) {
      if (x < st)
        vt.push_back(y++);
      else if (y > ed)
        vt.push_back(x--);
      else {
        if (abs(x) < abs(y))
          vt.push_back(y++);
        else
          vt.push_back(x--);
      }
    }
    sort(vt.begin(), vt.end());
  }
  for (int i = l, j = 0; i <= r; i += k, j++) a[i] = vt[j];
  return 1;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    if (s[0] == '?')
      a[i] = 1010000000;
    else
      a[i] = trans(s);
  }
  for (int i = 0; i < k; i++) {
    int last = -1, j;
    for (j = i; j < n; j += k)
      if (a[j] != 1010000000) {
        if (last == -1)
          solve(i, j - k, -1010000000, a[j] - 1);
        else {
          if (!solve(last + k, j - k, a[last] + 1, a[j] - 1)) {
            puts("Incorrect sequence");
            return 0;
          }
        }
        last = j;
      }
    if (last == -1)
      solve(i, j - k, -1010000000, 1010000000);
    else
      solve(last + k, j - k, a[last] + 1, 1010000000);
  }
  for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
  printf("%d\n", a[n - 1]);
  return 0;
}
