#include <bits/stdc++.h>
bool debug = false;
using namespace std;
long long convertToNum(string s) {
  long long val = 0;
  for (int i = 0; i < (s.size()); i++) val = val * 10 + s[i] - '0';
  return val;
}
string convertToString(long long a) {
  string res = "";
  if (!a) return "0";
  while (a) {
    res = (char)(a % 10 + 48) + res;
    a /= 10;
  }
  return res;
}
long long GCD(long long x, long long y) {
  if (!x) return y;
  if (!y) return x;
  if (x == y) return x;
  if (x < y)
    return GCD(x, y % x);
  else
    return GCD(x % y, y);
}
long long POW(long long x, long long y, long long Base) {
  if (!y) return 1;
  long long u = POW(x, y / 2, Base);
  u = (u * u) % Base;
  if (y & 1)
    return (u * x) % Base;
  else
    return u;
}
using namespace std;
int i, x, y, n, p, r, z, m, a[100100], b[100100], k[100100];
map<string, int> mm;
string st[100100];
char s[44];
bool cmp(int i, int j) {
  return (a[i] < a[j] || (a[i] == a[j] && st[i] > st[j]));
}
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s);
    st[i] = s;
    mm[st[i]] = i + 1;
    scanf("%d", &a[i]);
    k[i] = i;
  }
  sort(k, k + n, cmp);
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%d", &b[i]);
  sort(b, b + m);
  reverse(b, b + m);
  scanf("%s", s);
  x = mm[s] - 1;
  y = a[x] + b[0];
  p = 1;
  r = 1;
  for (i = 0; i < n; i++)
    if (k[i] != x) {
      if (st[k[i]] < st[x])
        z = y - a[k[i]] - 1;
      else
        z = y - a[k[i]];
      if (p >= n || b[p] > z) r++;
      p++;
    }
  printf("%d ", r);
  y = a[x] + b[n - 1];
  p = 0;
  r = 1;
  for (i = 0; i < n; i++)
    if (k[i] != x) {
      if (st[k[i]] < st[x])
        z = y - a[k[i]];
      else
        z = y - a[k[i]] + 1;
      if (p < n && b[p] >= z) {
        p++;
        r++;
      }
    }
  printf("%d\n", r);
  return 0;
}
