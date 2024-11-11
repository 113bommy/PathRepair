#include <bits/stdc++.h>
using namespace std;
int n, a[2007], b[2007], beg;
int lisu[2007][2007], lisd[2007][2007];
int lis1(int start) {
  int s[2], l[2007];
  memset(s, 0, sizeof(s));
  memset(l, 0, sizeof(l));
  int ret = 0;
  s[a[start]]++;
  l[start]++;
  for (int i = start + 1; i < n; i++) {
    int r = s[0];
    if (a[i]) r = max(r, s[1]);
    l[i] = max(1, r + 1);
    s[a[i]] = max(s[a[i]], l[i]);
    ret = max(ret, l[i]);
    lisu[start][i] = ret;
  }
  return ret;
}
int lis2(int start) {
  int s[2], l[2007];
  memset(s, 0, sizeof(s));
  memset(l, 0, sizeof(l));
  int ret = 0;
  s[b[start]]++;
  l[start]++;
  for (int i = start + 1; i < n; i++) {
    int r = s[0];
    if (b[i]) r = max(r, s[1]);
    l[i] = max(1, r + 1);
    s[b[i]] = max(s[b[i]], l[i]);
    ret = max(ret, l[i]);
    lisd[n - 1 - i][n - 1 - start] = ret;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], --a[i], b[i] = a[i];
  reverse(b, b + n);
  for (int i = 0; i < n; i++) lis1(i), lis2(i);
  int rk = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) rk = max(rk, lisd[i][j] - lisu[i][j]);
  std::cout << rk + lisu[0][n - 1] << '\n';
}
