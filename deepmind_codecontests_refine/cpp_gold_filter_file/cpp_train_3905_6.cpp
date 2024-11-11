#include <bits/stdc++.h>
using namespace std;
string s, l, r;
const int N = 100000;
const int M = 60;
const int MOD = 1e9 + 7;
int d, n;
int nxt[N][10], fail[N], ter[N], rt, tot;
int F[N][M];
queue<int> Q;
int solve(string t) {
  int p = rt, res = 0;
  for (int i = 0; i < t.size(); ++i) {
    for (int j = 0; j < t[i] - '0' + (i == t.size() - 1); ++j)
      res = (res + F[nxt[p][j]][t.size() - i - 1]) % MOD;
    p = nxt[p][t[i] - '0'];
  }
  return res;
}
int main() {
  cin >> s >> l >> r;
  d = l.size() / 2;
  n = s.size();
  rt = tot = 1;
  for (int i = 0; i <= n - d; ++i) {
    int p = rt;
    for (int j = 0; j < d; ++j) {
      if (!nxt[p][s[i + j] - '0']) nxt[p][s[i + j] - '0'] = ++tot;
      p = nxt[p][s[i + j] - '0'];
    }
    ter[p] = 1;
  }
  for (int i = 0; i < 10; ++i)
    if (nxt[rt][i]) {
      Q.push(nxt[rt][i]);
      fail[nxt[rt][i]] = rt;
    } else
      nxt[rt][i] = rt;
  while (!Q.empty()) {
    int t = Q.front();
    Q.pop();
    for (int i = 0; i < 10; ++i)
      if (nxt[t][i]) {
        Q.push(nxt[t][i]);
        fail[nxt[t][i]] = nxt[fail[t]][i];
      } else
        nxt[t][i] = nxt[fail[t]][i];
  }
  for (int i = 1; i <= tot; ++i)
    if (ter[i]) {
      F[i][0] = 1;
      for (int j = 0; j < 10; ++j) nxt[i][j] = i;
    }
  for (int i = 1; i <= l.size(); ++i)
    for (int j = 1; j <= tot; ++j)
      for (int k = 0; k < 10; ++k)
        F[j][i] = (F[nxt[j][k]][i - 1] + F[j][i]) % MOD;
  for (int i = l.size() - 1; ~i; --i)
    if (l[i] == '0')
      l[i] = '9';
    else {
      l[i]--;
      break;
    }
  cout << (solve(r) - solve(l) + MOD) % MOD << endl;
}
