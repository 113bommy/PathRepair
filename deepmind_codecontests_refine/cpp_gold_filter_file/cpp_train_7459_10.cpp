#include <bits/stdc++.h>
using namespace std;
template <typename Q>
inline char inin(Q &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x = f ? -x : x;
  return ch;
}
const int base[2] = {23, 91};
int n, m, k;
char s[500050], t[500050];
unsigned long long mi[2][500050];
struct wocao {
  unsigned long long x, y;
  wocao() {}
  wocao(unsigned long long x, unsigned long long y) : x(x), y(y) {}
  bool operator==(const wocao &rhs) const { return x == rhs.x && y == rhs.y; }
};
struct Hash {
  unsigned long long h[2][500050];
  void add(char *s) {
    for (int i = (0); i <= (1); i++) h[i][0] = s[0] - 'a';
    int len = strlen(s);
    for (int i = (1); i <= (len - 1); i++)
      for (int j = (0); j <= (1); j++)
        h[j][i] = h[j][i - 1] * base[j] + s[i] - 'a';
  }
  wocao hash(int l, int r) {
    unsigned long long x = h[0][r], y = h[1][r];
    if (!l) return wocao(x, y);
    x -= h[0][l - 1] * mi[0][r - l + 1];
    y -= h[1][l - 1] * mi[1][r - l + 1];
    return wocao(x, y);
  }
} ss, tt;
int l[500050], r[500050];
int main() {
  inin(n), inin(m), inin(k);
  scanf("%s", (s)), scanf("%s", (t));
  mi[0][0] = 1, mi[1][0] = 1;
  for (int i = (1); i <= (500000); i++)
    for (int j = (0); j <= (1); j++) mi[j][i] = mi[j][i - 1] * base[j];
  ss.add(s);
  tt.add(t);
  memset(l, -1, sizeof(l));
  memset(r, -1, sizeof(r));
  int temp = k - 1;
  for (int i = (0); i <= (min(m, k) - 1); i++) {
    while (temp < i) temp++;
    while (temp < n) {
      if (ss.hash(temp - i, temp) == tt.hash(0, i)) break;
      temp++;
    }
    if (ss.hash(k - i - 1, k - 1) == tt.hash(0, i)) temp = k - 1;
    l[i] = temp;
  }
  temp = n - k;
  for (int i = (0); i <= (min(m, k) - 1); i++) {
    while (n - temp < i) temp--;
    while (temp >= 0) {
      if (ss.hash(temp, temp + i) == tt.hash(m - 1 - i, m - 1)) break;
      temp--;
    }
    if (ss.hash(n - k, n - k + i) == tt.hash(m - 1 - i, m - 1)) temp = n - k;
    r[m - 1 - i] = temp;
  }
  int L, R, ans = 0;
  for (int i = (0); i <= (n - 1); i++) {
    if (l[i] != -1 && r[i + 1] != -1 && l[i] < r[i + 1]) {
      L = l[i] - k + 2;
      R = r[i + 1] + 1;
      ans = 1;
      break;
    }
  }
  if (k >= m && !ans) {
    temp = 0;
    for (int i = (0); i <= (m - 1); i++) {
      while (temp < i) temp++;
      while (temp < n) {
        if (ss.hash(temp - i, temp) == tt.hash(0, i)) break;
        temp++;
      }
    }
    if (temp + k < n) {
      L = max(1, temp - k + 1);
      R = max(temp, k - 1) + 2;
      ans = 1;
    } else {
      temp = n - 1;
      for (int i = (0); i <= (m - 1); i++) {
        while (n - temp < i) temp--;
        while (temp >= 0) {
          if (ss.hash(temp, temp + i) == tt.hash(m - 1 - i, m - 1)) break;
          temp--;
        }
      }
      if (temp - k >= 0) {
        L = min(n - k, temp) - k + 1;
        R = min(n - k, temp) + 1;
        ans = 1;
      }
    }
  }
  if (ans)
    printf("Yes\n%d %d", L, R);
  else
    cout << "No";
  return 0;
}
