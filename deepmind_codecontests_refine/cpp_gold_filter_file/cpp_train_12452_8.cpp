#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
bool f[MAXN];
string s;
int n;
bool check(int x) {
  for (int i = 0; i <= n; i++) f[i] = 0;
  int mn = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') mn = min(mn, i);
    if (s[i] == 'P') {
      if (i - mn > x) return false;
      mn = min(mn, i);
      f[min(mn, i)] = 1;
      break;
    }
  }
  for (int i = mn; i < n; i++) {
    if (s[i] == 'P') {
      int nxP = i + 1;
      while (s[nxP] != 'P' && nxP < n) nxP++;
      nxP--;
      int mx = 0, pL = n;
      for (int j = i; j >= 0; j--) {
        if (i - j > x) break;
        if (s[j] == '*' && f[j] == 1) pL = j;
        if (s[j] == 'P' && j != i) break;
        if (f[j] == 1) {
          int distL = i - j;
          if (i - j > x) continue;
          mx = max(mx, x - distL * 2);
          mx = max(mx, (x - distL) / 2);
        }
      }
      for (int j = pL; j <= i; j++) f[j + 1] = 1;
      for (int j = i; j <= min(n, min(i + mx, nxP)); j++) f[j + 1] = 1;
    }
    if (s[i] == '.') f[i + 1] = f[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '*')
      if (f[i + 1] == 0) return false;
  return true;
}
int bs(int l, int r) {
  int pos = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      pos = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return pos;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> s;
  cout << bs(1, n * 2);
  return 0;
}
