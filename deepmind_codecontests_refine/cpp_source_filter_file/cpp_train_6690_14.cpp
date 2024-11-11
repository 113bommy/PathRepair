#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
long long fac[1] = {1}, inv[1] = {1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long cmb(long long r, long long c) {
  return fac[r] * inv[c] % MOD * inv[r - c] % MOD;
}
int n, m, ob, flag = 0;
vector<int> v[500000];
vector<int> lv[500000];
char visit[500000];
vector<int> tmp;
void go(int o, int di) {
  tmp.push_back(o);
  lv[di].push_back(o);
  visit[o] = 1;
  if (di == ob - 1) {
    printf("PATH\n%d\n", ob);
    for (int i : tmp) printf("%d ", i + 1);
    printf("\n");
    flag = 1;
    return;
  }
  for (int i : v[o]) {
    if (!visit[i]) go(i, di + 1);
    if (flag == 1) return;
  }
  tmp.pop_back();
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    flag = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) v[i].clear(), lv[i].clear(), visit[i] = 0;
    tmp.clear();
    while (m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    ob = (n + 1) / 2;
    go(0, 0);
    if (flag == 0) {
      printf("PAIRING\n");
      vector<pair<int, int> > ans;
      for (int i = 0; i < n; i++) {
        for (int j = 1; j < (int)(lv[i]).size(); j++)
          ans.push_back({lv[i][j - 1] + 1, lv[i][j] + 1});
      }
      printf("%d\n", (int)(ans).size());
      for (pair<int, int> i : ans) printf("%d %d\n", i.first, i.second);
    }
  }
}
