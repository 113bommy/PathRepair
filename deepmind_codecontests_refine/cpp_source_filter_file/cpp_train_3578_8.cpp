#include <bits/stdc++.h>
using namespace std;
int cnt;
long long m, ans;
long long MOD = 1000000007;
long long f[15][15];
long long g[15][15];
int num[15];
inline void cal(long long x) {
  cnt = 0;
  memset(f, 0LL, sizeof(f));
  memset(g, 0LL, sizeof(g));
  while (x) {
    num[cnt++] = x % 10;
    x /= 10;
  }
  for (int k = 0; k <= 9; ++k) {
    if (k == 4 || k == 7) {
      if (k <= num[0]) f[1][1]++;
      g[1][1]++;
    } else {
      if (k <= num[0]) f[1][0]++;
      g[1][0]++;
    }
  }
  for (int i = 2; i <= cnt; ++i) {
    for (int x = 0; x < cnt; ++x) {
      for (int k = 0; k <= 9; ++k) {
        if (k < num[i - 1]) {
          if (k != 4 && k != 7)
            f[i][x] += g[i - 1][x];
          else if (x > 0)
            f[i][x] += g[i - 1][x - 1];
        } else if (k == num[i - 1]) {
          if (k != 4 && k != 7)
            f[i][x] += f[i - 1][x];
          else if (x > 0)
            f[i][x] += f[i - 1][x - 1];
        }
        if (k != 4 && k != 7)
          g[i][x] += g[i - 1][x];
        else if (x > 0)
          g[i][x] += g[i - 1][x - 1];
      }
    }
  }
}
void dfs(int cur, int fn, int sum, int* num) {
  if (cur == 7) {
    int tmp[8];
    for (int i = 0; i < 7; ++i) {
      tmp[i] = num[i];
    }
    sort(tmp, tmp + 7);
    int now = 0;
    int next = 0;
    long long res = 1LL;
    while (now < 7) {
      while (tmp[next] == tmp[now]) next++;
      for (long long i = 0; i < (long long)next - now; ++i)
        res = (res * ((f[cnt][tmp[now]] - i) % MOD)) % MOD;
      now = next;
    }
    ans = (ans + res) % MOD;
    return;
  }
  for (int x = 0; x <= cnt; ++x) {
    num[cur] = x;
    if (cur == 0)
      dfs(cur + 1, x, 0, num);
    else if (sum + x < fn)
      dfs(cur + 1, fn, sum + x, num);
  }
}
int main() {
  int num[8];
  while (cin >> m) {
    cal(m);
    ans = 0LL;
    --f[cnt][0];
    dfs(0, 0, 0, num);
    cout << ans << endl;
  }
  return 0 - 0;
}
