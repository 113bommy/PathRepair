#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int n, a[N], b[N], c[N], d[N], wc, wd, vi[N];
int sh[N], p[N];
int best[N];
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
int get(int n, int op) {
  int pos = rand() % n + 1;
  while (vi[pos] != op) pos = rand() % n + 1;
  return pos;
}
bool solve(int n, int b[]) {
  memset(vi, 0, sizeof(vi));
  memset(best, 0, sizeof(best));
  int m = n / 2, MIN, A = b[1], B = b[2], cnt = 1;
  vi[1] = 1;
  vi[2] = 2;
  MIN = abs(A - B);
  memcpy(best, vi, sizeof(vi));
  auto upd = [](double T, int &A, int &B, int da, int db) {
    int f = abs(A - B), g = abs(A + da - B - db);
    if (g < f || exp((g - f) / T) - (double)rand() / RAND_MAX >= 0) {
      A += da, B += db;
      return 1;
    }
    return 0;
  };
  double d, lim;
  if (n > 700)
    d = 0.99999, lim = 300000;
  else if (n > 500)
    d = 0.9999912, lim = 350000;
  else if (n > 100)
    d = 0.9999918, lim = 400000;
  else if (n > 30)
    d = 0.9999928, lim = 500000;
  else
    d = 0.999994, lim = 700000;
  for (double T = lim; T >= 1e-6; T *= d) {
    int op = (rand() & 3) + 1;
    while ((op == 1 && cnt == 1) || (op == 2 && cnt == m) ||
           (op == 3 && cnt + cnt == n))
      op = (rand() & 3) + 1;
    if (op == 1) {
      int x = get(n, 1), y = get(n, 2);
      vi[x] = vi[y] = 0;
      if (!upd(T, A, B, -b[x], -b[y]))
        vi[x] = 1, vi[y] = 2;
      else
        cnt--;
    }
    if (op == 2) {
      int x = get(n, 0), y;
      vi[x] = 1;
      y = get(n, 0);
      vi[y] = 2;
      if (!upd(T, A, B, b[x], b[y]))
        vi[x] = vi[y] = 0;
      else
        cnt++;
    }
    if (op == 3) {
      int now = rand() & 1;
      now++;
      int x = get(n, 0), y = get(n, now), da = 0, db = 0;
      vi[x] = now;
      vi[y] = 0;
      if (now == 1)
        da = b[x] - b[y];
      else
        db = b[x] - b[y];
      if (!upd(T, A, B, da, db)) vi[x] = 0, vi[y] = now;
    }
    if (op == 4) {
      int x = get(n, 1), y = get(n, 2);
      vi[x] = 2;
      vi[y] = 1;
      if (!upd(T, A, B, b[y] - b[x], b[x] - b[y])) vi[x] = 1, vi[y] = 2;
    }
    if (abs(A - B) < MIN) {
      MIN = abs(A - B);
      memcpy(best, vi, sizeof(vi));
    }
  }
  return MIN == 0;
}
signed main() {
  cerr << time(0) << endl;
  srand(time(0));
  n = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  sort(b + 1, b + 1 + n);
  int w = unique(b + 1, b + 1 + n) - b - 1;
  if (w != n) {
    printf("Yes\n");
    for (int i = 1; i <= w; i++) printf("%d ", b[i]);
    for (int i = 1; i <= n - w; i++) printf("0 ");
    printf("\n");
    return 0;
  }
  bool bl = 1;
  for (int i = 1; i <= n; i++)
    if (b[i] % 2 == 0) bl = 0;
  if (!bl) {
    int t[2];
    t[0] = t[1] = 0;
    for (int i = 1; i <= n; i++) t[b[i] & 1]++;
    int A = -1, B = -1, C = -1;
    for (int i = 1; i <= n && A == -1; i++)
      for (int j = 1; j < i && A == -1; j++) {
        t[b[i] & 1]--;
        t[b[j] & 1]--;
        int now = (b[i] + b[j]) % 2;
        if (t[now]) {
          A = i;
          B = j;
          for (int k = 1; k <= n; k++)
            if (k != i && k != j && now == b[k] % 2) C = k;
          break;
        }
        t[b[i] & 1]++;
        t[b[j] & 1]++;
      }
    if (A == -1) {
      printf("No\n");
      return 0;
    }
    a[1] = b[A] + b[B] - b[C];
    a[1] /= 2;
    for (int i = 1, j = 2; i <= n; i++)
      if (i != C) a[j++] = b[i] - a[1];
    printf("Yes\n");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
  }
  if (!solve(n, b))
    printf("No\n");
  else {
    for (int i = 1; i <= n; i++) {
      if (best[i] == 1) c[++wc] = b[i];
      if (best[i] == 2) d[++wd] = b[i];
    }
    int wh = 2;
    while (wc && wd) {
      a[wh] = c[wc--] - a[wh - 1];
      wh++;
      a[wh] = d[wd--] - a[wh - 1];
      wh++;
    }
    wh--;
    for (int i = 1; i <= n; i++)
      if (!best[i]) a[wh++] = b[i];
    printf("Yes\n");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
  }
}
