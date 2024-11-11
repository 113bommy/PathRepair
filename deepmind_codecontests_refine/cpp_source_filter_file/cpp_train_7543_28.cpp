#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:256000000")
int n, nn;
int st = 0;
int mas[100000];
int m[100000];
int pm[100000];
int chi[100000];
int chek_pr(int mid) {
  memset(chi, 0, sizeof chi);
  int k = 0;
  if (mid > nn / 2) {
    for (int i = 0; i < mid; ++i) chi[pm[i]]++;
    for (int i = mid; i < nn; ++i) chi[pm[i]]--;
    for (int i = 0; i <= n; ++i) {
      if (chi[i] < 0) return 0;
      if (chi[i] & 1) k++;
    }
    if (k - (nn & 1) > 0) return 0;
  } else {
    for (int i = 0; i < mid; ++i) chi[pm[i]]++;
    for (int i = nn - 1; i > nn - mid - 1; --i) {
      if (!chi[pm[i]]) return 0;
      chi[pm[i]]--;
    }
    for (int i = mid; i <= nn - mid - 1; ++i)
      if (pm[i] != pm[nn - i - 1]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &mas[i]);
  int q = 1;
  for (int i = 0; i < n; ++i)
    if (mas[i] != mas[n - 1 - i]) q = 0;
  if (q) {
    cout << n * (long long)(n + 1) / 2;
    return 0;
  }
  for (int i = 0; i < n; ++i) m[mas[i]]++;
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (m[i] & 1) t++;
  }
  t -= n & 1;
  if (t > 0) {
    cout << 0;
    return 0;
  }
  while (mas[st] == mas[n - 1 - st]) st++;
  for (int i = st; i < n - st; ++i) pm[nn++] = mas[i];
  int l = 0, r = nn - 1, mid, x = nn - 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chek_pr(mid)) {
      r = mid - 1;
      x = mid;
    } else {
      l = mid + 1;
    }
  }
  int prf = x;
  reverse(pm, pm + nn);
  l = 0, r = nn - 1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chek_pr(mid)) {
      r = mid - 1;
      x = mid;
    } else {
      l = mid + 1;
    }
  }
  int suf = x;
  cout << ((n - nn) / 2 + 1) *
              (long long)((n - nn) / 2 + 1 + 2 * n - prf - suf);
  return 0;
}
