#include <bits/stdc++.h>
using namespace std;
int n, k;
long long ln[10000], fac[15];
int cnt, ans, suf;
int tem[15];
void input() { scanf("%d%d", &n, &k); }
void dfs(long long x) {
  if (x > 1000000000) return;
  ln[cnt++] = x;
  dfs(x * 10 + 4);
  dfs(x * 10 + 7);
}
void make_lucky_number() {
  cnt = 0;
  dfs(4);
  dfs(7);
  sort(ln, ln + cnt);
}
void get_my_suf(int s) {
  bool used[15];
  memset(used, false, sizeof(used));
  for (int i = 1; i <= s; ++i) {
    int u = (k - 1) / fac[s - i];
    k -= (u * fac[s - i]);
    u++;
    for (int j = 1; j <= s; ++j) {
      if (!used[j]) u--;
      if (u == 0) {
        used[tem[i] = j] = true;
        break;
      }
    }
  }
}
bool check_lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
void solve() {
  fac[0] = fac[1] = 1;
  for (int i = 2; i <= 13; ++i) fac[i] = fac[i - 1] * i;
  if (n <= 13 && k > fac[n]) {
    puts("-1");
    return;
  }
  for (int i = 0; i < cnt; ++i)
    if (n - 13 < ln[i]) {
      ans = i;
      break;
    }
  suf = min(n, 13);
  get_my_suf(suf);
  for (int i = 1; i <= suf; ++i)
    if (check_lucky(n - suf + tem[i]) && check_lucky(n - suf + i)) ans++;
  printf("%d\n", ans);
}
int main() {
  input();
  make_lucky_number();
  solve();
  return 0;
}
