#include <bits/stdc++.h>
using namespace std;
int n, k;
int kil[1000006];
int a[1000006];
int lll(int a, int b) {
  int c = a;
  int d = b;
  while (c && d) {
    c %= d;
    if (c) d %= c;
  }
  return a / (c + d) * b;
}
int m[500005];
int pref[500005];
int suf[500005];
int main() {
  int n, a, b, t;
  cin >> n >> a >> b >> t;
  char c;
  cin.get();
  int pos = 0;
  int mr = 0;
  int mp = -1;
  int ms = -1;
  int d;
  for (long long i = 0; i < n; ++i) {
    scanf("%c", &c);
    m[i] = (c == 'w');
    if (i == 0) {
      pref[i] = 0;
      d = 1 + m[i] * b;
    } else
      pref[i] = pref[i - 1] + 1 + m[i] * b + a;
    if (d + pref[i] <= t) mp = i;
  }
  suf[n] = 0;
  for (long long i = n - 1; i >= 0; --i) {
    suf[i] = suf[i + 1] + 1 + m[i] * b + a;
    if (d + suf[i] <= t) ms = i;
  }
  if (mp == -1 && ms == -1) {
    cout << 0;
    return 0;
  };
  if (mp == -1) {
    cout << n - ms;
    return 0;
  };
  if (ms == -1) {
    cout << mp + 1;
    return 0;
  };
  mr = max(n - ms, mp + 1);
  int cr;
  int p1 = mp;
  int p2 = ms;
  p2 = n;
  while (p1 > 0) {
    while (p2 >= 0 && p1 < p2 &&
           pref[p1] + suf[p2] + d + a * (min(p1, n - p2)) <= t)
      --p2;
    ++p2;
    cr = p1 + 1 + n - p2;
    mr = max(mr, cr);
    --p1;
  }
  p1 = 0;
  p2 = ms;
  while (p2 < n) {
    while (p1 < n && p1 < p2 &&
           pref[p1] + suf[p2] + d + a * (min(p1, n - p2)) <= t)
      ++p1;
    --p1;
    cr = p1 + 1 + n - p2;
    mr = max(mr, cr);
    ++p2;
  }
  cout << mr;
}
