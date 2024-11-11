#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 228;
const int big = 2e9;
const int md = 1e9 + 7;
string a, b;
int a1, a2, n, m, pr[N][26], sf[N][26], j, pr1[N], sf1[N], ans;
bool ok(int l, int r) {
  int t1, t2;
  if (l == 0)
    t1 = -2;
  else
    t1 = pr1[l - 1];
  if (r == m - 1)
    t2 = n + 2;
  else
    t2 = sf1[r + 1];
  if (t1 == -1 || t2 == -1) return 0;
  return t1 < t2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> a;
  cin >> b;
  n = (int)a.size();
  m = (int)b.size();
  for (int j = 0; j < (int)n; j++) {
    int x = a[j] - 'a';
    if (j > 0)
      for (int k = 0; k < (int)26; k++) pr[j][k] = pr[j - 1][k];
    else
      for (int k = 0; k < (int)26; k++) pr[j][k] = -1;
    pr[j][x] = j;
  }
  for (int j = n - 1; j >= 0; j--) {
    int x = a[j] - 'a';
    if (j != n - 1)
      for (int k = 0; k < (int)26; k++) sf[j][k] = sf[j + 1][k];
    else
      for (int k = 0; k < (int)26; k++) sf[j][k] = -1;
    sf[j][x] = j;
  }
  j = 0;
  for (int i = 0; i < (int)m; i++) {
    int x = b[i] - 'a';
    if (j >= n) j = -1;
    if (j != -1) j = sf[j][x];
    pr1[i] = j;
    if (j != -1) j++;
  }
  if (pr1[m - 1] != -1) {
    cout << b;
    return 0;
  }
  j = n - 1;
  for (int i = m - 1; i >= 0; i--) {
    int x = b[i] - 'a';
    if (j < 0) j = -1;
    if (j != -1) j = pr[j][x];
    sf1[i] = j;
    if (j != -1) j--;
  }
  for (int i = 0; i < (int)m; i++) {
    int l = i;
    int r = m - 1;
    while (l < r) {
      int d = (l + r) >> 1;
      if (ok(i, d))
        r = d;
      else
        l = d + 1;
    }
    if (ok(i, l)) {
      if (ans < m - (l - i + 1)) {
        a1 = i;
        a2 = l;
        ans = m - (l - i + 1);
      }
    }
  }
  if (ans == 0) {
    cout << "-";
    return 0;
  }
  for (int i = 0; i < a1; i++) cout << b[i];
  for (int i = a2 + 1; i < m; i++) cout << b[i];
  return 0;
}
