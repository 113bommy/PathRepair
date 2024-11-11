#include <bits/stdc++.h>
using namespace std;
inline long long pow(long long a, long long b, int mod) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
struct Info {
  bitset<50005> f[35], frths[35];
};
int n, p;
int an[35], bn[35], atn0[35];
bool visn[35];
Info fn[35];
inline int g_pw10_la(int a) {
  int pw10_len_a = 1;
  for (int t = a; t; t /= 10) pw10_len_a *= 10;
  return pw10_len_a;
}
inline void add_number(const Info &info, int a, Info &ret) {
  int pw10_len_a = g_pw10_la(a);
  for (int i = 0; i < 64; ++i)
    for (int j = 0; j < p; ++j)
      if (info.f[i][j]) {
        if (!ret.f[i][j]) {
          ret.f[i][j] = true;
          ret.frths[i][j] = false;
        }
        int nxti = i ^ a, nxtj = (j * pw10_len_a % p + a) % p;
        ret.f[nxti][nxtj] = true;
        ret.frths[nxti][nxtj] = true;
      }
}
int main() {
  int n0;
  scanf("%d%d", &n0, &p);
  for (int i = 1; i <= n0; ++i) {
    int a;
    scanf("%d", &a);
    if (a >= 32) continue;
    ++n;
    an[n] = a;
    bn[a] = n;
    atn0[n] = i;
  }
  fn[0].f[0][0] = true;
  for (int i = 1; i <= n; ++i) add_number(fn[i - 1], an[i], fn[i]);
  bool ok = false;
  for (int i = 1; i <= n; ++i)
    if (fn[i].frths[0][0]) ok = true;
  if (ok) {
    puts("Yes");
    if (p != 2 && p != 5) {
      for (int k = n, i = 0, j = 0; k >= 1; --k) {
        if (!fn[k].frths[i][j]) continue;
        visn[k] = true;
        int a = an[k];
        i ^= a;
        j = (int)(((long long)j - a % p + p) % p * pow(g_pw10_la(a), p - 2, p) %
                  p);
      }
    } else {
      int lst = -1;
      for (int i = n; i >= 1; --i)
        if (fn[i].frths[0][0]) {
          lst = i;
          break;
        }
      visn[lst] = true;
      int i = an[lst];
      for (int k = lst - 1; k >= 1; --k) {
        int okj = -1;
        for (int j = 0; j < p; ++j)
          if (fn[k].frths[i][j]) {
            okj = j;
            break;
          }
        if (okj == -1) continue;
        visn[k] = true;
        i ^= an[k];
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
      if (visn[i]) ++cnt;
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i)
      if (visn[i]) printf("%d%c", atn0[i], " \n"[--cnt == 0]);
  } else
    puts("No");
  return 0;
}
