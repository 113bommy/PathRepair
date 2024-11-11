#include <bits/stdc++.h>
using namespace std;
int a[10], b[10];
char c[300001], d[300001];
int id[100000], lid;
bool canget(int u, int v) {
  if (!a[u]) return false;
  if (!b[v]) return false;
  int rs = 0;
  a[u]--;
  b[v]--;
  int res = 0, mn;
  for (int i = 0; i <= 8; i++) {
    res += a[i];
    mn = min(res, b[8 - i]);
    res -= mn;
    rs += mn;
  }
  a[u]++;
  b[v]++;
  return rs >= lid - 1;
}
int main() {
  cin >> c;
  int m, n = strlen(c);
  m = n;
  for (int i = 0; i < n; i++) {
    a[c[i] - '0']++;
    b[c[i] - '0']++;
  }
  int q = 1, i, st = -1, mx = 0, mn, col;
  for (int i = 1; i <= 9; i++) {
    if (!a[i]) continue;
    if (!b[10 - i]) continue;
    a[i]--;
    b[10 - i]--;
    col = 1;
    for (int i = 1; i <= 8; i++) col += min(a[i], b[9 - i]);
    if (col > mx) mx = col, st = i;
    a[i]++;
    b[10 - i]++;
  }
  if (st != -1) {
    a[st]--;
    b[10 - st]--;
    n--;
    c[n] = st + '0';
    d[n] = 10 - st + '0';
    for (int i = 0; i <= 9; i++) {
      mn = min(a[i], b[9 - i]);
      for (int j = 0; j < mn; j++) {
        n--;
        c[n] = i + '0';
        d[n] = 9 - i + '0';
        a[i]--;
        b[9 - i]--;
      }
    }
  }
  if (n == 0) {
    cout << c << endl << d;
    return 0;
  }
  id[lid++] = --n;
  int K = 0;
  while (K < lid - 1) {
    int u = -1, j;
    for (int i = 1; i <= 8 && u != -1; i++) {
      for (int j = 8; j >= 1 && u != -1; j--) {
        if (a[i] && b[j] && i + j <= 8) u = i;
      }
    }
    if (u == -1) {
      if (a[0] > b[0]) {
        u = 0;
      } else {
        u = 8;
        while (!a[u]) u--;
      }
    }
    j = 8;
    while (!b[j] || u + j > 8) j--;
    c[id[K]] = u + '0';
    d[id[K]] = j + '0';
    a[u]--;
    b[j]--;
    K++;
  }
  q = id[lid - 1];
  mn = min(a[0], b[0]);
  for (int i = 0; i < mn; i++) {
    c[m] = d[m] = '0';
    m++;
    a[0]--;
    b[0]--;
  }
  if (q < 0) {
    cout << c << endl << d;
    return 0;
  }
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < a[i]; j++) c[q--] = i + '0';
  q = id[lid - 1];
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < b[i]; j++) d[q--] = i + '0';
  cout << c + q + 1 << endl << d + q + 1;
  return 0;
}
