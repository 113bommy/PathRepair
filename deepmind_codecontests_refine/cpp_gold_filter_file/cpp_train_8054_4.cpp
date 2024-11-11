#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t = 102;
int n, p;
long long ans[103] = {
    10LL,         31LL,         42LL,         51LL,         72LL,
    90LL,         131LL,        152LL,        190LL,        271LL,
    392LL,        400LL,        572LL,        581LL,        812LL,
    850LL,        1202LL,       1211LL,       1742LL,       1790LL,
    2552LL,       2601LL,       3632LL,       3820LL,       5372LL,
    5441LL,       7802LL,       8050LL,       11462LL,      11691LL,
    16322LL,      17180LL,      24152LL,      24471LL,      35072LL,
    36220LL,      51542LL,      52601LL,      73412LL,      77300LL,
    108662LL,     110111LL,     157802LL,     162980LL,     231902LL,
    236691LL,     330332LL,     347840LL,     488942LL,     495491LL,
    710072LL,     733400LL,     1043522LL,    1065101LL,    1486472LL,
    1565270LL,    2200202LL,    2229701LL,    3195302LL,    3300290LL,
    4695812LL,    4792941LL,    6689102LL,    7043710LL,    9900872LL,
    10033641LL,   14378822LL,   14851300LL,   21131132LL,   21568221LL,
    30100922LL,   31696690LL,   44553902LL,   45151371LL,   64704662LL,
    66830840LL,   95090072LL,   97056981LL,   135454112LL,  142635100LL,
    200492522LL,  203181161LL,  291170942LL,  300738770LL,  427905302LL,
    436756401LL,  609543482LL,  641857940LL,  902216312LL,  914315211LL,
    1310269202LL, 1353324460LL, 1925573822LL, 1965403791LL, 2742945632LL,
    2888360720LL, 4059973382LL, 4114418441LL, 5896211372LL, 6089960060LL,
    8665082162LL, 8844317051LL};
long long st[103];
long long cnt[5];
bool w[10000][5];
long long d[10000][5];
long long dfs(int u, int k) {
  if (u == n) return !!k;
  if (w[u][k]) return d[u][k];
  w[u][k] = 1;
  d[u][k] = 0;
  for (int i = 0; i < 3; i++)
    d[u][k] = (d[u][k] + cnt[i] * dfs(u + 1, k ^ i)) % mod;
  return d[u][k];
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 0; i < t; i++) st[i] = ans[i] / 10, ans[i] %= 10;
  t = lower_bound(st, st + t, p) - st;
  st[t] = p + 1;
  for (int i = 0; i < t; i++) {
    int l = st[i], r = min(st[i + 1], 1LL * p) - 1;
    cnt[ans[i]] =
        (cnt[ans[i]] + 1LL * mod +
         ((1LL * p * (r - l + 1)) % mod - (1LL * r * (r + 1) / 2) % mod +
          (1LL * l * (l - 1) / 2) % mod) %
             mod) %
        mod;
  }
  cout << dfs(0, 0) << endl;
  return 0;
}
