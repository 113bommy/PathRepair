#include <bits/stdc++.h>
using namespace std;
int n;
long long f[1 << 18], g[385], h[1 << 18], S[18][1 << 18];
map<vector<int>, int> mp;
vector<vector<int> > parti;
vector<int> cur;
void dfs(int sum, int lst) {
  if (sum < lst) return;
  cur.push_back(sum);
  mp[cur] = parti.size();
  parti.push_back(cur);
  cur.pop_back();
  for (int i = lst; i <= sum; i++) {
    cur.push_back(i);
    dfs(sum - i, i);
    cur.pop_back();
  }
}
long long dp[1 << 18][18];
bool flag[18][18];
char s[20];
void fwt(long long* A, int l, int flag) {
  for (int i = 1; i < (1 << l); i <<= 1) {
    for (int j = 0; j < (1 << l); j += (i << 1)) {
      for (int k = 0; k < i; k++) {
        if (flag == 1)
          A[i + j + k] += A[j + k];
        else
          A[i + j + k] -= A[j + k];
      }
    }
  }
}
int coef[1 << 18];
int main() {
  scanf("%d", &n);
  dfs(n, 1);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < n; j++) flag[i][j] = s[j] - '0';
  }
  for (int i = 0; i < n; i++) dp[1 << i][i] = 1;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        for (int k = 0; k < n; k++) {
          if (!((i >> k) & 1) && flag[j][k]) {
            dp[i | (1 << k)][k] += dp[i][j];
          }
        }
        S[__builtin_popcount(i)][i] += dp[i][j];
      }
    }
  }
  for (int i = 0; i <= n; i++) fwt(S[i], n, 1);
  int tS = (1 << n) - 1;
  for (int i = 0; i < (1 << n); i++)
    coef[i] = __builtin_parity(tS ^ i) ? -1 : 1;
  for (int i = 0; i < parti.size(); i++) {
    const auto& x = parti[i];
    fill(h, h + (1 << n), 1);
    for (int j = 0; j < x.size(); j++)
      for (int k = 0; k < (1 << n); k++) h[k] *= S[x[j]][k];
    for (int j = 0; j < (1 << n) - 1; j++) h[(1 << n) - 1] += coef[j] * h[j];
    g[i] = h[(1 << n) - 1];
  }
  for (int i = 0; i < (1 << (n - 1)); i++) {
    vector<int> c;
    int ccnt = 1;
    for (int j = 0; j < (n - 1); j++) {
      if (!((i >> j) & 1)) {
        c.push_back(ccnt);
        ccnt = 0;
      }
      ccnt++;
    }
    c.push_back(ccnt);
    sort(c.begin(), c.end());
    f[i] = g[mp[c]];
  }
  for (int i = 0; i < (n - 1); i++) {
    for (int j = 0; j < (1 << (n - 1)); j++) {
      if (!((j >> i) & 1)) f[j] -= f[j | (1 << i)];
    }
  }
  for (int i = 0; i < (1 << (n - 1)); i++) printf("%lld ", f[i]);
  return 0;
}
