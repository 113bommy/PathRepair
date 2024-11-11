#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
struct node {
  int u, v;
  node(int u = 0, int v = 0) : u(u), v(v) {}
  bool operator<(const node &B) const { return u < B.u; }
} Spell[MAXN], Zone[MAXN << 1];
int n, m, k;
int spl = 0, Split[MAXN << 1];
int zone = 0, csp;
int las, nowsp, link, spell[8];
int FL(int p) {
  int l = 1, r = zone;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (Zone[mid].u == p) return mid;
    if (Zone[mid].u < p)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}
int FR(int p) {
  int l = 1, r = zone;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (Zone[mid].v == p) return mid;
    if (Zone[mid].v < p)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}
int lasdp[567], dp[567];
int Cnt_One(int v) {
  int ans = 0;
  while (v) {
    v -= 1 << __builtin_ctz(v);
    ans++;
  }
  return ans;
}
void Solve(int p) {
  int l = Zone[p].v - Zone[p].u + 1;
  for (int i = 0; i < 8; i++)
    if ((las & (1 << i)) && Spell[spell[i]].v < p) las ^= (1 << i);
  link = nowsp = las;
  while (Spell[csp].u == p) {
    for (long long i = 0; i <= 7; i++)
      if ((nowsp & (1 << i)) == 0) {
        nowsp ^= (1 << i);
        spell[i] = csp;
        break;
      }
    csp++;
  }
  memset(lasdp, 0, sizeof(lasdp));
  for (long long i = 0; i <= (1 << 8) - 1; i++)
    lasdp[i & link] = max(lasdp[i & link], dp[i]);
  memset(dp, 0, sizeof(dp));
  for (long long i = 0; i <= (1 << 8) - 1; i++)
    if ((nowsp & i) == i) {
      if (Cnt_One(i) & 1)
        dp[i] = lasdp[i & link] + l;
      else
        dp[i] = lasdp[i & link];
    }
  las = nowsp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  int u, v;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    Spell[i] = node(u, v);
    Split[++spl] = u;
    Split[++spl] = v + 1;
  }
  sort(Spell + 1, Spell + n + 1);
  sort(Split + 1, Split + spl + 1);
  for (int i = 1; i <= spl; i++)
    if (Split[i] != Split[i + 1])
      Zone[++zone] = node(Split[i], Split[i + 1] - 1);
  for (long long i = 1; i <= n; i++)
    Spell[i] = node(FL(Spell[i].u), FR(Spell[i].v));
  csp = 1;
  for (long long i = 1; i <= zone; i++) Solve(i);
  int res = 0;
  for (long long i = 0; i <= (1 << 7) - 1; i++) res = max(res, dp[i]);
  cout << res << endl;
}
