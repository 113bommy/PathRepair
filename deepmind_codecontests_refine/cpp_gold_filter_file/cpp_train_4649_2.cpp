#include <bits/stdc++.h>
using namespace std;
long long a[300005];
int n;
long long c[300005][6][2];
long long rm[300005][6][2];
void clc(int i, int j) {
  for (int t = (0); t < (2); t++) {
    vector<long long> v(a + i, a + j);
    if (t) reverse(v.begin(), v.end());
    c[i][j - i][t] = 0;
    for (int k = (0); k < (int(v.size()) - 1); k++) {
      long long r = min(v[k], v[k + 1]);
      c[i][j - i][t] += r;
      v[k] -= r;
      v[k + 1] -= r;
    }
    c[i][j - i][t] += v.back();
    rm[i][j - i][t] = v.back();
    for (int k = (0); k < (int(v.size()) - 1); k++) {
      if (v[k] != 0) {
        c[i][j - i][t] = 1e12;
      }
    }
  }
}
long long cdp[300005][2];
int coptl[300005][2];
int coptl2[300005][2];
int coptb[300005][2];
long long dp(int i, bool p0) {
  if (i == n) return 0;
  if (i == n - 1 && p0) return 0;
  if (cdp[i][p0] != -1) return cdp[i][p0];
  long long &res = cdp[i][p0] = 1e18;
  for (int l = (1); l < (6); l++) {
    if (i + l < n) {
      long long cc = c[i][l][0];
      long long rr = rm[i][l][0];
      if (rr <= a[i + l]) {
        long long nres = cc + dp(i + l + 1, a[i + l] - rr == 0);
        if (nres < res) {
          res = nres;
          coptb[i][p0] = 1;
          coptl[i][p0] = l;
        }
      }
      for (int l2 = (1); l2 < (6); l2++) {
        if (i + l + 1 + l2 <= n) {
          long long cc2 = c[i + l + 1][l2][1];
          long long rr2 = rm[i + l + 1][l2][1];
          if (rr + rr2 <= a[i + l]) {
            long long nres = cc + cc2 + dp(i + l + l2 + 1, true);
            if (nres < res) {
              res = nres;
              coptb[i][p0] = 2;
              coptl[i][p0] = l;
              coptl2[i][p0] = l2;
            }
          }
        }
      }
    }
  }
  if (p0) {
    long long nres = dp(i + 1, a[i] == 0);
    if (nres < res) {
      res = nres;
      coptb[i][p0] = 3;
    }
    for (int l = (1); l < (6); l++) {
      if (i + 1 + l <= n) {
        long long cc = c[i + 1][l][1];
        long long rr = rm[i + 1][l][1];
        if (rr <= a[i]) {
          long long nres = cc + dp(i + l + 1, true);
          if (nres < res) {
            res = nres;
            coptb[i][p0] = 4;
            coptl[i][p0] = l;
          }
        }
      }
    }
  }
  return res;
}
vector<int> ans;
void bt(int i, int p0) {
  if (i == n) return;
  if (i == n - 1 && p0) return;
  if (coptb[i][p0] == 1) {
    int l = coptl[i][p0];
    for (int j = (i); j < (i + l); j++) {
      if (a[j] > 0 && a[j + 1] > 0) {
        int r = min(a[j], a[j + 1]);
        a[j] -= r;
        a[j + 1] -= r;
        ans.emplace_back(j + 1);
      }
    }
    bt(i + l + 1, a[i + l] == 0);
  }
  if (coptb[i][p0] == 2) {
    int l = coptl[i][p0];
    for (int j = (i); j < (i + l); j++) {
      if (a[j] > 0 && a[j + 1] > 0) {
        int r = min(a[j], a[j + 1]);
        a[j] -= r;
        a[j + 1] -= r;
        ans.emplace_back(j + 1);
      }
    }
    int l2 = coptl2[i][p0];
    for (int j = i + l + l2; j > i + l; j--) {
      if (a[j - 1] > 0 && a[j] > 0) {
        int r = min(a[j - 1], a[j]);
        a[j - 1] -= r;
        a[j] -= r;
        ans.emplace_back(j);
      }
    }
    bt(i + l + 1 + l2, true);
  }
  if (coptb[i][p0] == 3) {
    bt(i + 1, a[i] == 0);
  }
  if (coptb[i][p0] == 4) {
    int l = coptl[i][p0];
    for (int j = i + l; j > i; j--) {
      if (a[j - 1] > 0 && a[j] > 0) {
        int r = min(a[j - 1], a[j]);
        a[j - 1] -= r;
        a[j] -= r;
        ans.emplace_back(j);
      }
    }
    bt(i + l + 1, true);
  }
}
int main() {
  memset(cdp, -1, sizeof cdp);
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%lld", a + i);
  for (int i = (0); i < (n); i++) {
    for (int l = (1); l < (6); l++) {
      if (i + l <= n) {
        clc(i, i + l);
      }
    }
  }
  long long rdp = dp(0, true);
  bt(0, true);
  printf("%d\n", int(ans.size()));
  for (int x : ans) printf("%d\n", x);
}
