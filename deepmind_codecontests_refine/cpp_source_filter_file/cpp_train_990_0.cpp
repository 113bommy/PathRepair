#include <bits/stdc++.h>
using namespace std;
const int inf = 999999999;
const int mod = 1000000007;
inline int Getint() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  int ret = 0;
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return ret;
}
long long f[1000010][3];
int a[1000010];
int n, costa, costb;
inline void Add(set<int> &s, int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      s.insert(x);
      while (x % i == 0) x /= i;
    }
  }
  if (x != 1) s.insert(x);
}
inline bool Check(int x, int y) {
  return x % y == 0 || (x - 1) % y == 0 || (x + 1) % y == 0;
}
inline bool Check2(int x, int y) { return x % y != 0; }
inline long long Calc(int x) {
  memset(f, 0, sizeof(f));
  f[0][0] = 0;
  f[0][1] = f[0][2] = (long long)inf * inf;
  for (int i = 1; i <= n; i++) {
    f[i][0] = f[i][1] = f[i][2] = (long long)inf * inf;
    if (Check(a[i], x)) {
      int cur = Check2(a[i], x);
      f[i][0] = min(f[i][0], f[i - 1][0] + Check2(a[i], x) * costb);
      f[i][2] =
          min(f[i][0], min(f[i - 1][1], f[i - 1][2]) + Check2(a[i], x) * costb);
    }
    f[i][1] = min(f[i][1], min(f[i - 1][0], f[i - 1][1]) + costa);
  }
  return min(f[n][0], min(f[n][1], f[n][2]));
}
inline void Work() {
  set<int> s;
  Add(s, a[1] - 1), Add(s, a[1]), Add(s, a[1] + 1);
  Add(s, a[n] - 1), Add(s, a[n]), Add(s, a[n] + 1);
  long long ans = (long long)inf * inf;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    ans = min(ans, Calc(*it));
  }
  cout << ans << endl;
}
int main() {
  n = Getint(), costa = Getint(), costb = Getint();
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = Getint();
  }
  Work();
  return 0;
}
