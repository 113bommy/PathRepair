#include <bits/stdc++.h>
using namespace std;
namespace thecold {
inline int read() {
  int res = 0;
  bool flag = false;
  char c = getchar();
  while (!isdigit(c)) flag = (c == '-'), c = getchar();
  while (isdigit(c)) res = res * 10 + (c ^ 48), c = getchar();
  return !flag ? res : -res;
}
const int Max_n = 105;
const int jzp = 1e9 + 7;
int id[Max_n << 1][Max_n << 1], tot, cnt, tmp[Max_n << 1];
int a1, a2, a3, a4, r, f[Max_n * Max_n][Max_n << 1];
long long sum, inv, p1, p2, p3, p4;
inline int quickpow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % jzp;
    x = x * x % jzp, y >>= 1;
  }
  return ret;
}
inline int ID(int x, int y) {
  x += r + 1, y += r + 1;
  if (id[x][y]) return id[x][y];
  return id[x][y] = ++tot;
}
inline int add(const int x, const int y) {
  int ret = x + y;
  if (ret >= jzp) ret -= jzp;
  return ret;
}
int a[Max_n << 1][Max_n << 1], ans[Max_n << 1];
inline void Guass() {
  const int n = 2 * r + 1;
  for (int i = 1; i <= n; ++i) {
    if (!a[i][i])
      for (int j = i + 1; j <= n; ++j)
        if (a[j][i]) {
          swap(a[i], a[j]);
          break;
        }
    long long inv = quickpow(a[i][i], jzp - 2);
    for (int j = i + 1; j <= n; ++j) {
      int ki = jzp - inv * a[j][i] % jzp;
      a[j][0] = add(a[j][0], 1ll * ki * a[i][0] % jzp);
      for (int k = i; k <= n; ++k)
        a[j][k] = add(a[j][k], 1ll * ki * a[i][k] % jzp);
    }
  }
  for (int i = n; i; --i) {
    ans[i] = 1ll * a[i][0] * quickpow(a[i][i], jzp - 2) % jzp;
    for (int j = i - 1; j; --j)
      a[j][0] = add(a[j][0], jzp - 1ll * a[j][i] * ans[i] % jzp);
  }
}
inline void main() {
  r = read(), sum += (a1 = read()), sum += (a2 = read()), sum += (a3 = read()),
  sum += (a4 = read()), sum = quickpow(sum, jzp - 2);
  p1 = sum * a1 % jzp, p2 = sum * a2 % jzp, p3 = sum * a3 % jzp,
  p4 = sum * a4 % jzp, inv = quickpow(p3, jzp - 2);
  if (r == 1) {
    puts("1");
    return;
  }
  for (int y = -r; y <= r; ++y) {
    int x = sqrt(r * r - y * y);
    id[-x + r + 1][y + r + 1] = ++tot, f[ID(-x, y)][ID(-x, y)] = 1;
  }
  for (int x = -r; x <= r; ++x)
    for (int y = -r; y <= r; ++y)
      if (x * x + y * y <= r * r && !id[x + r + 1][y + r + 1])
        id[x + r + 1][y + r + 1] = ++tot;
  for (int x = -r; x <= r; ++x)
    for (int y = r; y >= -r; --y)
      if (x * x + y * y <= r * r && ID(x, y) > 2 * r + 1) {
        for (int i = 0; i <= 2 * r + 1; ++i)
          f[ID(x, y)][i] =
              inv *
              add(f[ID(x - 1, y)][i],
                  add(jzp - p1 * f[ID(x - 2, y)][i] % jzp,
                      add(jzp - p2 * f[ID(x - 1, y - 1)][i] % jzp,
                          jzp - p4 * f[ID(x - 1, y + 1)][i] % jzp))) %
              jzp;
        f[ID(x, y)][0] = add(f[ID(x, y)][0], jzp - inv);
      }
  for (int y = r; y >= -r; --y) {
    int x = sqrt(r * r - y * y) + 1;
    ++cnt;
    for (int i = 0; i <= 2 * r + 1; ++i)
      a[cnt][i] = inv *
                  add(f[ID(x - 1, y)][i],
                      add(jzp - p1 * f[ID(x - 2, y)][i] % jzp,
                          add(jzp - p2 * f[ID(x - 1, y - 1)][i] % jzp,
                              jzp - p4 * f[ID(x - 1, y + 1)][i] % jzp))) %
                  jzp;
    a[cnt][0] = add(a[cnt][0], jzp - inv), a[cnt][0] = jzp - a[cnt][0];
  }
  Guass();
  int ret = 0, pos = ID(0, 0);
  for (int i = 1; i <= 2 * r + 1; ++i)
    ret = add(ret, 1ll * f[pos][i] * ans[i] % jzp);
  ret = add(ret, f[pos][0]);
  printf("%d\n", ret);
}
}  // namespace thecold
int main() {
  thecold::main();
  return 0;
}
