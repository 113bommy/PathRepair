#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
std::mt19937 rnd(time(NULL));
template <class T>
void cxk(T& a, T b) {
  a = a > b ? a : b;
}
template <class T>
void cnk(T& a, T b) {
  a = a < b ? a : b;
}
int pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % 1000000007;
    x = 1ll * x * x % 1000000007;
    y >>= 1;
  }
  return ret;
}
template <class Ta, class Tb>
void inc(Ta& a, Tb b) {
  a = a + b >= 1000000007 ? a + b - 1000000007 : a + b;
}
template <class Ta, class Tb>
void dec(Ta& a, Tb b) {
  a = a >= b ? a - b : a + 1000000007 - b;
}
int p[200010];
bool yes[2000010];
int d[2000010], pr[200010], P, pd[2000010];
int pw[200010], cnt[200010];
int main() {
  int n = gi();
  for (int i = 2; i <= 200000; ++i) {
    if (!yes[i]) pr[++P] = i, d[i] = P, pd[i] = 1;
    for (int j = 1; j <= P && i * pr[j] <= 200000; ++j) {
      yes[i * pr[j]] = 1;
      d[i * pr[j]] = j;
      if (i % pr[j] == 0) {
        pd[i * pr[j]] = pd[i] + 1;
        break;
      }
      pd[i * pr[j]] = 1;
    }
  }
  for (int i = 1; i <= n; ++i)
    p[i] = std::lower_bound(pr + 1, pr + P + 1, gi()) - pr;
  std::sort(p + 1, p + n + 1);
  for (int i = n; i; --i) {
    int x = pr[p[i]];
    if (!pw[p[i]])
      pw[p[i]] = cnt[p[i]] = 1, p[i] = 0;
    else {
      --x;
      while (x > 1) {
        int y = d[x], py = pd[x];
        if (pw[y] < py)
          pw[y] = py, cnt[y] = 1;
        else if (pw[y] == py)
          ++cnt[y];
        while (x % pr[y] == 0) x /= pr[y];
      }
    }
  }
  int qwq = 0;
  for (int i = 1; i <= n; ++i) {
    int x = pr[p[i]] - 1, now = 1;
    while (x > 1) {
      int y = d[x], py = pd[x];
      if (pw[y] == py && cnt[y] == 1) now = 0;
      while (x % pr[y] == 0) x /= pr[y];
    }
    if (x == 1) qwq |= now;
  }
  int ans = 1;
  for (int i = 1; i <= P; ++i) ans = 1ll * ans * pow(pr[i], pw[i]) % 1000000007;
  printf("%d\n", (ans + qwq) % 1000000007);
  return 0;
}
