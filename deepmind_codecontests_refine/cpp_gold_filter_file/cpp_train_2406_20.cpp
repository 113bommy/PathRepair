#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MAXN = (int)1e6 + 5;
const int MODDP = (int)998244353;
const int MODH = (int)1e9 + 7;
const int B = 43;
char s[MAXN];
string a, l, r;
int ha[MAXN], hl[MAXN], hr[MAXN], powb[MAXN];
int dp[MAXN], sdp[MAXN];
void hashem(int ar[], string& s) {
  for (int i = s.size() - 1; i >= 0; --i)
    ar[i] = (1LL * ar[i + 1] * B % MODH + (s[i] - '0')) % MODH;
}
int gethash(int ar[], int lb, int rb) {
  return (ar[lb] - 1LL * powb[rb + 1 - lb] * ar[rb + 1] % MODH + MODH) % MODH;
}
int lsz, rsz;
int getDP(int lb, int rb) { return (sdp[lb] - sdp[rb + 1] + MODDP) % MODDP; }
int main() {
  scanf("%s", s);
  a = s;
  scanf("%s", s);
  l = s;
  lsz = l.size();
  scanf("%s", s);
  r = s;
  rsz = r.size();
  powb[0] = 1;
  for (int i = 1; i < MAXN; ++i) powb[i] = 1LL * powb[i - 1] * B % MODH;
  hashem(ha, a);
  hashem(hl, l);
  hashem(hr, r);
  dp[a.size()] = 1;
  sdp[a.size()] = 1;
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] == '0') {
      if (l.size() == 1 && l[0] == '0')
        dp[i] = dp[i + 1];
      else {
        dp[i] = 0;
      }
    } else {
      if (a.size() - i < lsz) goto CC;
      int dpL, dpR;
      int lb = 0, rb = lsz - 1;
      int sln = -1;
      while (lb <= rb) {
        int mid = (lb + rb) / 2;
        if (gethash(ha, i, i + mid) == gethash(hl, 0, mid)) {
          sln = max(sln, mid);
          lb = mid + 1;
        } else
          rb = mid - 1;
      }
      if (sln == lsz - 1)
        dpL = i + lsz;
      else if (a[i + sln + 1] >= l[sln + 1])
        dpL = i + lsz;
      else
        dpL = i + lsz + 1;
      if (dpL > a.size()) goto CC;
      if (a.size() - i < rsz) dpR = a.size();
      lb = 0, rb = rsz - 1;
      sln = -1;
      while (lb <= rb) {
        int mid = (lb + rb) / 2;
        if (gethash(ha, i, i + mid) == gethash(hr, 0, mid)) {
          sln = max(sln, mid);
          lb = mid + 1;
        } else
          rb = mid - 1;
      }
      if (sln == rsz - 1)
        dpR = i + rsz;
      else if (a[i + sln + 1] <= r[sln + 1])
        dpR = i + rsz;
      else
        dpR = i + rsz - 1;
      if (dpR < dpL) goto CC;
      dp[i] = getDP(dpL, dpR);
    }
  CC:
    sdp[i] = (dp[i] + sdp[i + 1]) % MODDP;
  }
  cout << dp[0];
  return 0;
}
