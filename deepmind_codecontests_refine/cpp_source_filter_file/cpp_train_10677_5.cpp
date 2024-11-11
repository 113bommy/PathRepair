#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long Inf = 1e10;
const int P = 1e9 + 7;
const int N = 100005;
inline long long IN() {
  long long x = 0;
  int ch = 0, f = 0;
  for (ch = getchar(); ch != -1 && (ch < 48 || ch > 57); ch = getchar())
    f = (ch == '-');
  for (; ch >= 48 && ch <= 57; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return f ? (-x) : x;
}
template <typename T>
inline int chkmin(T &a, const T &b) {
  if (b < a) return a = b, 1;
  return 0;
}
template <typename T>
inline int chkmax(T &a, const T &b) {
  if (b > a) return a = b, 1;
  return 0;
}
void renew(int &x, const int &y) {
  x += y;
  if (x >= P) x -= P;
  if (x < 0) x += P;
}
int Pow(int x, int y, int p) {
  int a = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) a = (long long)a * x % p;
  return a;
}
int n, m, s;
int w[N], id[N];
int cmp(const int &a, const int &b) { return w[a] > w[b]; }
int res[3005][3005];
int main() {
  scanf("%d%d", &m, &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", w + i);
  sort(w + 1, w + n + 1);
  reverse(w + 1, w + n + 1);
  s = m * (m - 1);
  for (int i = (int)(1); i <= (int)(n); i++) s -= w[i];
  if (s < 0) {
    puts("no");
    return 0;
  }
  if (n < m) {
    for (int i = (int)(n + 1); i <= (int)(m); i++) {
      w[i] = w[n];
      s -= w[i];
    }
    if (s > 0) {
      puts("no");
      return 0;
    }
    s = -s;
    int x = m;
    for (int i = (int)(1); i <= (int)(s); i++) {
      w[x]--;
      x--;
      if (x == n) x = m;
    }
  }
  int sum = 0;
  for (int i = (int)(m); i >= (int)(1); i--) {
    sum += w[i];
    if (sum < (m - i) * (m - i - 1)) {
      puts("no");
      return 0;
    }
  }
  puts("yes");
  n = m;
  for (int i = (int)(1); i <= (int)(n); i++) id[i] = i;
  for (int i = (int)(1); i <= (int)(n); i++) {
    sort(id + i, id + n + 1, cmp);
    int u = id[i];
    int win = 0, draw = 0, lose = 0;
    if (w[u] & 1) {
      win = w[u] / 2;
      draw = 1;
    } else {
      win = w[u] / 2;
      draw = 0;
    }
    lose = n - i - win - draw;
    int j = i + 1;
    for (int u = (int)(1); u <= (int)(lose); u++) {
      w[id[j]] -= 2;
      res[id[i]][id[j]] = 1;
      res[id[j]][id[i]] = -1;
      j++;
    }
    for (int u = (int)(1); u <= (int)(draw); u++) {
      w[id[j]] -= 1;
      res[id[i]][id[j]] = 0;
      res[id[j]][id[i]] = 0;
      j++;
    }
    for (int u = (int)(j); u <= (int)(n); u++) {
      res[id[i]][id[u]] = -1;
      res[id[u]][id[i]] = 1;
    }
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    for (int j = (int)(1); j <= (int)(n); j++) {
      char w = 'L';
      if (i == j)
        w = 'X';
      else if (res[i][j] == -1)
        w = 'W';
      else if (res[i][j] == 0)
        w = 'D';
      putchar(w);
    }
    puts("");
  }
  return 0;
}
