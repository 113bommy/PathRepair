#include <bits/stdc++.h>
using namespace std;
void set(int& n, int first) { n = n | (1 << first); }
void reset(int& n, int first) { n = n & ~(1 << first); }
bool check(int n, int first) { return (bool)(n & (1 << first)); }
const int mx = 100005;
int a[mx], k;
bool f[mx];
bool fun(int s, int e, int v1, int v2) {
  if (v2 <= v1) return false;
  int c = (e - s - k) / k;
  if (c > v2 - v1 - 1) return false;
  int m = -c / 2, st, i;
  if (m <= v1) {
    st = v1 + 1;
    for (i = s + k; i < e; i += k) a[i] = st++;
  } else if (m + c >= v2) {
    st = v2 - 1;
    for (i = e - k; i > s; i -= k) a[i] = st--;
  } else {
    for (i = s + k; i < e; i += k) a[i] = m++;
  }
  return true;
}
int main() {
  int i, j, n;
  while (scanf("%d%d", &n, &k) == 2) {
    memset(f, false, sizeof f);
    for (i = 1; i <= n; i++) {
      char ch, sign = '+';
      while (scanf("%c", &ch) && (ch == ' ' || ch == '\n'))
        ;
      int t = 0;
      while (true) {
        if (ch == '?') {
          f[i] = true;
          break;
        } else if (ch == '-')
          sign = '-';
        else if (ch == ' ' || ch == '\n')
          break;
        else
          t = t * 10 + ch - '0';
        scanf("%c", &ch);
      }
      if (sign == '-') t = -t;
      a[i] = t;
    }
    int s = -k, e = 0;
    a[0] = -2e9;
    bool flag = false;
    for (i = 1; i <= k; i++) {
      int v1 = -1e9 - 1, t = 0;
      s = i - k;
      for (j = i; j <= n; j += k) {
        if (f[j])
          t++;
        else if (s >= i && j > i && a[j] <= a[s])
          flag = true;
        else {
          if (t > 0 && (!fun(s, j, v1, a[j]))) flag = true;
          t = 0;
          s = j;
          v1 = a[j];
        }
        if (flag) break;
      }
      if (s < n) {
        if (!fun(s, j, v1, 2e9))
          ;
      }
      if (flag) break;
    }
    if (flag)
      printf("Incorrect sequence\n");
    else {
      for (i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", a[i]);
      }
      printf("\n");
    }
  }
}
