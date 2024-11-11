#include <bits/stdc++.h>
using namespace std;
int n;
int st[30];
int c[100007];
int b[100007];
long long getRe(int l, int r, int u) {
  if (l >= r - 1) {
    return 0;
  }
  if (u >= 26) {
    long long p = r - l;
    return (p * (p - 1) / 2);
  }
  int lp = l;
  int rp = r;
  while (lp < rp) {
    if ((c[lp] % st[u + 1]) / st[u] == 1) {
      if ((c[rp - 1] % st[u + 1]) / st[u] == 0) {
        swap(c[lp], c[rp - 1]);
        lp++;
        rp--;
      } else {
        rp--;
      }
    } else {
      lp++;
    }
  }
  int m = lp;
  long long re = getRe(l, m, u + 1) + getRe(m, r, u + 1);
  lp = 0;
  rp = m;
  long long lastL = 0;
  long long lastR = 0;
  while (lp + rp - m < r) {
    if (lp == m) {
      b[lp + rp - m] = c[rp];
      rp++;
      continue;
    }
    if (rp == r) {
      b[lp + rp - m] = c[lp];
      lp++;
      continue;
    }
    if (c[lp] > c[rp]) {
      b[lp + rp - m] = c[rp];
      lastR = 0;
      rp++;
      continue;
    }
    if (c[lp] < c[rp] - st[u]) {
      b[lp + rp - m] = c[lp];
      lastL = 0;
      lp++;
      continue;
    }
    if (lp != m - 1 && c[lp] == c[lp + 1]) {
      b[lp + rp - m] = c[lp];
      lastL++;
      lp++;
      continue;
    }
    if (rp != r - 1 && c[rp] == c[rp + 1]) {
      b[lp + rp - m] = c[rp];
      lastR++;
      rp++;
      continue;
    }
    re += (lastL + 1) * (lastR + 1);
    b[lp + rp - m] = c[lp];
    swap(b[lp + rp - m], b[lp + rp - m - lastR]);
    lastL = 0;
    lp++;
  }
  for (int i = l; i < r; i++) {
    c[i] = b[i];
  }
  return re;
}
int main() {
  st[0] = 1;
  for (int i = 1; i < 30; i++) {
    st[i] = 2 * st[i - 1];
  }
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      c[i] ^= st[s[j] - 'a'];
    }
  }
  cout << getRe(0, n, 0);
  return 0;
}
