#include <bits/stdc++.h>
using namespace std;
const long long N = 2000002, M = 26;
const int mod = 51123987;
char s[N];
int pre[N], suf[N];
struct pam {
  bool vis[N];
  vector<pair<int, int> > nxt[N];
  int fail[N];
  int len[N];
  char S[N];
  int cnt[N], num[N];
  int last, n, p;
  int newnode(int l) {
    nxt[p].clear();
    cnt[p] = num[p] = 0;
    len[p] = l;
    return p++;
  }
  void init() {
    p = 0;
    newnode(0);
    newnode(-1);
    last = n = 0;
    S[n] = -1;
    fail[0] = 1;
  }
  int get_fail(int x) {
    while (S[n - len[x] - 1] != S[n]) x = fail[x];
    return x;
  }
  void add(int c, int pos, int fg) {
    c -= 'a';
    S[++n] = c;
    int cur = get_fail(last);
    int kkk = -1;
    for (int i = 0; i < nxt[cur].size(); i++)
      if (nxt[cur][i].first == c) kkk = nxt[cur][i].second;
    if (kkk == -1) {
      int now = newnode(len[cur] + 2);
      int kk = 0;
      for (int i = 0; i < nxt[get_fail(fail[cur])].size(); i++)
        if (nxt[get_fail(fail[cur])][i].first == c)
          kk = nxt[get_fail(fail[cur])][i].second;
      fail[now] = kk;
      nxt[cur].push_back({c, now});
      kkk = now;
      num[now] = num[fail[now]] + 1;
    }
    last = kkk;
    cnt[last]++;
    if (!fg)
      pre[pos] = num[last];
    else
      suf[pos] = (suf[pos + 1] + num[last]) % mod;
  }
  void Count() {
    for (int i = p - 1; i >= 0; --i)
      cnt[fail[i]] = (cnt[fail[i]] + cnt[i]) % mod;
  }
} p;
int main() {
  int n, m, t = 1, cas = 1;
  scanf("%d", &n);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  p.init();
  for (int i = 1; i <= n; i++) p.add(s[i], i, 0);
  p.init();
  suf[n + 1] = 0;
  for (int i = n; i; i--) p.add(s[i], i, 1);
  long long ans = 0;
  for (int i = 1; i < n; i++)
    ans = (ans + 1ll * pre[i] * suf[i + 1] % mod) % mod;
  p.Count();
  long long sum = 0;
  for (int i = 2; i < p.p; i++) sum = (p.cnt[i] + sum) % mod;
  printf("%lld\n", (1ll * sum * (sum - 1) / 2 + mod - ans) % mod);
  return 0;
}
