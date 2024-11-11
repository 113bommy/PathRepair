#include <bits/stdc++.h>
using namespace std;
int IN() {
  int c, f, x;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  c == '-' ? (f = 1, x = 0) : (f = 0, x = c - '0');
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
  return !f ? x : -x;
}
const int N = 500 + 19;
const int p = 1e9 + 7;
char s[N];
int w[N], v[N], f[N][1 << 16];
int n, m, res, num;
void U(int &x, int y) { x = (x + y) % p; }
void O(int *A, int *B, int *res) {
  static int a[1 << 16], b[1 << 16], c[1 << 16];
  for (int t = 0; t < 1 << 16; t++) {
    a[t] = A[t];
    b[t] = B[t];
  }
  for (int i = 0; i < 16; i++)
    for (int t = 0; t < 1 << 16; t++)
      if (!(t >> i & 1)) {
        U(a[t | 1 << i], a[t]);
        U(b[t | 1 << i], b[t]);
      }
  for (int t = 0; t < 1 << 16; t++) c[t] = 1ll * a[t] * b[t] % p;
  for (int i = 0; i < 16; i++)
    for (int t = 0; t < 1 << 16; t++)
      if (!(t >> i & 1)) {
        U(c[t | 1 << i], p - c[t]);
      }
  for (int t = 0; t < 1 << 16; t++) U(res[t], c[t]);
}
void A(int *A, int *B, int *res) {
  static int a[1 << 16], b[1 << 16], c[1 << 16];
  for (int t = 0; t < 1 << 16; t++) {
    a[65535 - t] = A[t];
    b[65535 - t] = B[t];
    c[t] = 0;
  }
  O(a, b, c);
  for (int t = 0; t < 1 << 16; t++) {
    U(res[65535 - t], c[t]);
  }
}
int Work(int l, int r) {
  int x = ++num;
  if (l == r) {
    for (int i = 0; i < 4; i++)
      if (s[l] == '?' || s[l] == 'A' + i) {
        int s = 0;
        for (int t = 0; t < 16; t++) s |= (t >> i & 1) << t;
        f[x][s]++;
      }
    for (int i = 0; i < 4; i++)
      if (s[l] == '?' || s[l] == 'a' + i) {
        int s = 0;
        for (int t = 0; t < 16; t++) s |= (t >> i & 1 ^ 1) << t;
        f[x][s]++;
      }
  } else {
    int tmp = 0, mid, lsn, rsn;
    for (int i = l; i < r + 1; i++) {
      if (s[i] == '(') tmp++;
      if (s[i] == ')')
        if (--tmp == 0) {
          mid = i + 1;
          break;
        }
    }
    lsn = Work(l + 1, mid - 2);
    rsn = Work(mid + 2, r - 1);
    if (s[mid] == '?' || s[mid] == '|') O(f[lsn], f[rsn], f[x]);
    if (s[mid] == '?' || s[mid] == '&') A(f[lsn], f[rsn], f[x]);
  }
  return x;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  m = IN();
  for (int t = 0; t < m; t++) {
    for (int i = 0; i < 4; i++) w[t] |= IN() << i;
    v[t] = IN();
  }
  Work(1, n);
  for (int t = 0; t < 1 << 16; t++) {
    int b = 1;
    for (int i = 0; i < m; i++) {
      if ((t >> w[i] & 1) != v[i]) {
        b = 0;
        break;
      }
    }
    if (b) res = (res + f[1][t]) % p;
  }
  printf("%d\n", res);
}
