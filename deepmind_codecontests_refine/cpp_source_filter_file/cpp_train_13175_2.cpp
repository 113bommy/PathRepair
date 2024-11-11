#include <bits/stdc++.h>
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::vector;
const int maxn = 400007;
const int mod = 1e9 + 7;
long long fast_pow(long long b, int k) {
  long long s = 1;
  while (k) {
    if (k & 1) s - s* b % mod;
    b = b * b % mod;
    k >>= 1;
  }
  return s;
}
char s[maxn];
int N, Q;
int lef[maxn], rig[maxn];
long long val[maxn];
int stk[maxn], top;
int pid[maxn], pcnt, pl[maxn], pr[maxn];
long long psum[maxn];
int nid[maxn], ncnt, z[maxn];
long long pre[maxn], nval[maxn], prod[maxn];
long long p10[maxn];
long long getnum(int l, int r) {
  if (s[r] == ')')
    return val[r];
  else
    return (pre[r] - pre[l - 1] * p10[r - l + 1] % mod + mod) % mod;
}
long long getp(int l, int r) {
  if (nid[l] == nid[r]) return getnum(l, r);
  long long re = getnum(l, rig[l]) * getnum(lef[r], r) % mod;
  l = rig[l] + 2;
  r = lef[r] - 2;
  if (l > r) return re;
  l = nid[l];
  r = nid[r];
  if (z[r] - z[l - 1] > 0) return 0;
  return prod[r] * fast_pow(prod[l - 1], mod - 2) % mod * re % mod;
}
int build(int l, int r) {
  vector<int> p, v;
  for (int i = l; i <= r; i = rig[i] + 2) {
    p.push_back(i);
    if (s[i] == '(') val[i] = val[rig[i]] = build(i + 1, rig[i] - 1);
    v.push_back(getnum(i, rig[i]));
  }
  int tl, tr;
  for (int i = 0; i < p.size(); i++) {
    tl = p[i];
    tr = rig[tl];
    nval[++ncnt] = v[i];
    if (s[tl] == '(')
      nid[tl] = nid[tr] = ncnt;
    else
      for (int k = tl; k <= tr; k++) nid[k] = ncnt;
  }
  vector<int> a;
  a.push_back(0);
  for (int i = 1; i < p.size(); i++)
    if (s[p[i] - 1] == '+') a.push_back(i);
  a.push_back(p.size());
  long long pro, re = 0;
  for (int i = 0; i + 1 < a.size(); i++) {
    tl = a[i], tr = a[i + 1] - 1;
    pro = 1;
    ++pcnt;
    pl[pcnt] = p[tl];
    pr[pcnt] = rig[p[tr]];
    for (int k = tl; k <= tr; k++) {
      pro = pro * v[k] % mod;
      if (s[p[k]] == '(')
        pid[p[k]] = pid[rig[p[k]]] = pcnt;
      else
        for (int j = p[k]; j <= rig[p[k]]; j++) pid[j] = pcnt;
    }
    psum[pcnt] = (psum[pcnt - 1] + pro) % mod;
    re = (re + pro) % mod;
  }
  return re;
}
int sum[maxn], st[21][maxn], lg[maxn];
void Pre() {
  for (int i = 1; i <= N; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == '(')
      sum[i]++;
    else if (s[i] == ')')
      sum[i]--;
  }
  for (int i = 2; i <= N; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= N; i++) st[0][i] = sum[i];
  for (int k = 1; k <= lg[N]; k++)
    for (int i = 1; i <= N - (1 << k) + 1; i++)
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << k - 1)]);
  return;
}
int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}
int judge(int l, int r) {
  return s[l] == '+' || s[l] == '*' || s[r] == '+' || s[r] == '*' ||
         query(l, r) != sum[r] || sum[r] != sum[l - 1];
}
int main() {
  scanf("%s", s + 2);
  N = strlen(s + 2);
  scanf("%d", &Q);
  Pre();
  s[1] = '(';
  s[N + 2] = ')';
  N += 2;
  for (int i = 1; i <= N; i++) {
    if (isdigit(s[i])) {
      if (isdigit(s[i - 1]))
        lef[i] = lef[i - 1];
      else
        lef[i] = i;
    } else if (s[i] == ')')
      lef[i] = stk[top--];
    else if (s[i] == '(')
      stk[++top] = i, lef[i] = i;
  }
  for (int i = N; i > 0; i--) {
    if (isdigit(s[i])) {
      if (isdigit(s[i + 1]))
        rig[i] = rig[i + 1];
      else
        rig[i] = i;
    } else if (s[i] == '(')
      rig[i] = stk[top--];
    else if (s[i] == ')')
      stk[++top] = i, rig[i] = i;
  }
  for (int i = 1; i <= N; i++)
    if (isdigit(s[i])) pre[i] = (pre[i - 1] * 10 + s[i] - '0') % mod;
  for (int i = p10[0] = 1; i <= N; i++) p10[i] = p10[i - 1] * 10 % mod;
  val[1] = val[N] = build(2, N - 1);
  for (int i = prod[0] = 1; i <= ncnt; i++) {
    z[i] = z[i - 1] + (nval[i] == 0);
    prod[i] = prod[i - 1];
    if (nval[i]) (prod[i] *= nval[i]) %= mod;
  }
  int l, r;
  long long ans;
  while (Q--) {
    scanf("%d%d", &l, &r);
    l++;
    r++;
    if (judge(l, r)) {
      puts("-1");
      continue;
    }
    if (nid[l] == nid[r])
      printf("%lld\n", getnum(l, r));
    else if (pid[l] == pid[r])
      printf("%lld\n", getp(l, r));
    else {
      ans = (getp(l, pr[pid[l]]) + getp(pl[pid[r]], r)) % mod;
      l = pid[l] + 1;
      r = pid[r] - 1;
      if (l <= r) ans = (ans + psum[r] - psum[l - 1] + mod) % mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
