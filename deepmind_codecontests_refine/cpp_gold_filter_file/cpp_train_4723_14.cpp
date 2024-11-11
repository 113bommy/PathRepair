#include <bits/stdc++.h>
using namespace std;
const int maxn = 700 + 10;
class bignum {
 public:
  deque<int> d;
  inline int size() { return d.size(); }
  inline void resize(int k) { d.resize(k); }
  inline void equal(int x) {
    d.resize(0);
    while (x > 0) {
      d.push_back(x % 10);
      x /= 10;
    }
  }
  inline void get() {
    string s;
    cin >> s;
    d.resize(0);
    for (int i = 0; i < s.size(); ++i) d.push_front(s[i] - '0');
  }
  inline void print() {
    for (int i = d.size() - 1; i >= 0; --i) cout << d[i];
  }
  inline void make_good() {
    while (d.size() > 0 && d[d.size() - 1] == 0) d.pop_back();
    if (d.size() == 0) return;
    for (int i = 0; i < d.size() - 1; ++i) d[i + 1] += d[i] / 10, d[i] %= 10;
    while (d[d.size() - 1] > 9)
      d.push_back(d[d.size() - 1] / 10), d[d.size() - 2] %= 10;
  }
};
int n;
vector<int> v[maxn];
bignum dp[maxn];
bignum ch[maxn];
int vis[maxn];
vector<int> child[maxn];
inline bignum operator*(bignum &fi, int se) {
  bignum ret;
  ret.resize(0);
  ret = fi;
  for (int i = 0; i < ret.size(); ++i) ret.d[i] *= se;
  ret.make_good();
  return ret;
}
inline bignum operator+(bignum &fi, bignum &se) {
  bignum ret;
  int Max = max(fi.size(), se.size());
  int Min = min(fi.size(), se.size());
  ret.resize(Max);
  for (int i = 0; i < Min; ++i) ret.d[i] = fi.d[i] + se.d[i];
  for (int i = Min; i < fi.size(); ++i) ret.d[i] = fi.d[i];
  for (int i = Min; i < se.size(); ++i) ret.d[i] = se.d[i];
  ret.make_good();
  return ret;
}
inline bignum operator*(bignum &fi, bignum &se) {
  bignum ret;
  bignum hlp;
  ret.resize(0);
  for (int i = 0; i < fi.size(); ++i) {
    hlp.resize(0);
    hlp = se * fi.d[i];
    for (int j = 0; j < i; ++j) hlp.d.push_front(0);
    hlp.make_good();
    ret = ret + hlp;
  }
  return ret;
}
inline bool operator<(bignum &fi, bignum &se) {
  if (fi.size() != se.size()) return fi.size() < se.size();
  for (int i = fi.size() - 1; i >= 0; --i)
    if (fi.d[i] != se.d[i]) return fi.d[i] < se.d[i];
  return false;
}
int cp;
bignum r1, r2;
inline bool operator==(bignum &fi, bignum &se) {
  if (fi.size() != se.size()) return false;
  for (int i = fi.size() - 1; i >= 0; --i)
    if (fi.d[i] != se.d[i]) return false;
  return true;
}
inline bool cmp(int i1_, int i2_) {
  r1.resize(0);
  r2.resize(0);
  r1 = dp[i1_] * ch[i2_];
  r2 = dp[i2_] * ch[i1_];
  if (r1 == r2)
    return i1_ < i2_;
  else
    return !(r1 < r2);
}
deque<bignum> DP[maxn];
deque<bignum> CH[maxn];
vector<bignum> c[maxn];
bignum hlp[maxn], hlp_[maxn];
inline void update(int st) {
  dp[st].equal(1);
  ch[st].equal(1);
  for (int i = 0; i < child[st].size(); ++i) ch[st] = ch[st] * dp[child[st][i]];
  if (child[st].size() > 0) sort(child[st].begin(), child[st].end(), cmp);
  bignum Max;
  Max.equal(1);
  for (int i = 0; i < child[st].size(); ++i) Max = Max * ch[child[st][i]];
  Max = Max * (child[st].size() + 1);
  if (Max < ch[st]) Max = ch[st];
  bignum now;
  now.resize(0);
  now.equal(1);
  if (child[st].size() > 0) {
    DP[st].push_back(dp[child[st][0]]);
    for (int i = 1; i < child[st].size(); ++i)
      DP[st].push_back(DP[st][i - 1] * dp[child[st][i]]);
  }
  bignum F;
  F.equal(1);
  CH[st].push_front(F);
  for (int i = (int)child[st].size() - 1; i >= 0; --i)
    CH[st].push_front(CH[st][0] * ch[child[st][i]]);
  now.equal(1);
  for (int i = 0; i < child[st].size(); ++i) {
    now.equal(1);
    now = now * DP[st][i];
    now = now * CH[st][i + 1];
    now = now * ((int)child[st].size() - i);
    if (Max < now) Max = now;
  }
  if (child[st].size() > 0) {
    hlp[0] = dp[child[st][0]];
    for (int i = 1; i < child[st].size(); ++i)
      hlp[i] = hlp[i - 1] * dp[child[st][i]];
  }
  hlp_[child[st].size()].equal(1);
  for (int i = child[st].size() - 1; i >= 0; --i)
    hlp_[i] = hlp_[i + 1] * dp[child[st][i]];
  if (child[st].size() > 0) {
    c[st].push_back(hlp_[1]);
    for (int i = 1; i < child[st].size(); ++i)
      c[st].push_back(hlp[i - 1] * hlp_[i + 1]);
  }
  bignum now_;
  now_.equal(1);
  for (int l = child[st].size() - 1; l >= 0; --l) {
    now_.equal(1);
    int mask = child[st][l];
    now.equal(1);
    for (int i = 0; i < child[mask].size(); ++i) now = now * ch[child[mask][i]];
    now_ = c[st][l];
    now = now * now_;
    now = now * ((int)child[mask].size() + 2);
    if (Max < now) Max = now;
    for (int i = 0; i < child[mask].size(); ++i) {
      now.equal(1);
      now = now_;
      now = now * DP[mask][i];
      now = now * CH[mask][i + 1];
      now = now * ((int)child[mask].size() - i + 1);
      if (Max < now) Max = now;
    }
  }
  dp[st].resize(0);
  dp[st] = Max;
}
inline void DFS(int st) {
  vis[st] = 1;
  for (int i = 0; i < v[st].size(); ++i)
    if (vis[v[st][i]] == 0) child[st].push_back(v[st][i]), DFS(v[st][i]);
  update(st);
}
inline void check() {
  bignum fi, se, ret;
  while (1) {
    fi.get();
    se.get();
    ret = fi * se;
    ret.print();
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int v1, v2;
    cin >> v1 >> v2;
    v[v1].push_back(v2);
    v[v2].push_back(v1);
  }
  DFS(1);
  dp[1].print();
  cout << endl;
  return 0;
}
