#include <bits/stdc++.h>
using namespace std;
long long dp[57][57][57][2];
int len;
long long licz3(int la, int pa, int lb, int pb, long long s) {
  len = max(la, lb);
  while ((1LL << len) < s) len++;
  for (int a = 0; a <= pa; ++a)
    for (int b = 0; b <= pb; ++b) dp[0][a][b][0] = dp[0][a][b][1] = 0;
  dp[0][0][0][0] = 1;
  for (int i = 1; i <= len + 1; ++i) {
    bool aok;
    bool bok;
    for (int a = 0; a <= pa; ++a) {
      aok = (i - 1 < la) && a;
      for (int b = 0; b <= pb; ++b) {
        dp[i][a][b][0] = dp[i][a][b][1] = 0;
        bok = (i - 1 < lb) && b;
        if ((1LL << (i - 1)) & s) {
          dp[i][a][b][0] = dp[i - 1][a][b][1];
          if (aok) dp[i][a][b][0] += dp[i - 1][a - 1][b][0];
          if (bok) dp[i][a][b][0] += dp[i - 1][a][b - 1][0];
          if (aok && bok) dp[i][a][b][1] = dp[i - 1][a - 1][b - 1][1];
        } else {
          dp[i][a][b][0] = dp[i - 1][a][b][0];
          if (aok) dp[i][a][b][1] = dp[i - 1][a - 1][b][1];
          if (bok) dp[i][a][b][1] += dp[i - 1][a][b - 1][1];
          if (aok && bok) dp[i][a][b][1] += dp[i - 1][a - 1][b - 1][0];
        }
      }
    }
  }
  return dp[len + 1][pa][pb][0];
}
long long licz(int la, int lb, long long s) {
  long long res = 0;
  for (int ps = 0; ps <= la + lb; ++ps) {
    if ((s + ps) % 2 == 0) {
      if ((1LL << la) + (1LL << lb) - 2 >= (s + ps) / 2) {
        licz3(la, min(ps, la), lb, min(ps, lb), (s + ps) / 2);
        for (int pa = 0; pa <= min(la, ps); ++pa) {
          int pb = ps - pa;
          if (pb <= lb) res += dp[len + 1][pa][pb][0];
        }
      }
    }
  }
  return res;
}
int licz2(int la, long long s) {
  int res = 0;
  for (int pop = 0; pop <= la; ++pop) {
    long long a = s + pop;
    if (a % 2 == 0) {
      if (__builtin_popcount(a / 2) == pop) res++;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long s;
  cin >> s;
  long long res = 0;
  for (int la = 1; la <= 50; ++la) {
    long long P = (1LL << la) - 1;
    long long sn = s - P;
    if (sn < 0) break;
    res += licz2(la - 1, sn % P);
  }
  for (int la = 2; la <= 50; ++la) {
    for (int lb = 2; lb <= 50; ++lb) {
      long long P = (1LL << la) + (1LL << lb) - 3;
      long long sn = s - P - (1LL << (lb - 1)) + 1;
      if (sn < 0) continue;
      res += licz(la - 2, lb - 2, sn % P);
    }
  }
  cout << res << endl;
  return 0;
}
