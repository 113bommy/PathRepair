#include <bits/stdc++.h>
using namespace std;
int p[1100000];
bool d[1100000];
int kubelki[1100000];
bitset<1100000> dp;
int last[1100000];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  vector<int> V;
  for (int i = 0; i < n; ++i) {
    if (d[i] == false) {
      int s = p[i];
      int ile = 1;
      while (s != i) {
        d[s] = true;
        ++ile;
        s = p[s];
      }
      ++kubelki[ile];
    }
  }
  dp[0] = true;
  for (int i = k; i > 100; --i)
    while (kubelki[i]) {
      dp |= (dp >> i);
      --kubelki[i];
    }
  for (int i = min(100, k); i > 0 && dp[k] == false; --i)
    if (kubelki[i]) {
      for (int j = 0; j < i; ++j) last[j] = 1000000000;
      last[0] = 1;
      int rest = -1;
      for (int j = i; j <= k; ++j) {
        ++rest;
        if (rest == i) rest = 0;
        if (dp[j])
          last[rest] = 0;
        else if (last[rest] <= kubelki[i])
          dp[j] = true;
        ++last[rest];
      }
    }
  int ilenp = 0;
  for (int i = 1; i <= n; i += 2) ilenp += kubelki[i];
  int ilepodwojnych = (n - ilenp) / 2;
  int resmax = 0;
  if (k < ilepodwojnych)
    resmax = 2 * k;
  else
    resmax = min(n, k + ilepodwojnych);
  int resmin = (dp[k] ? k : k + 1);
  printf("%d %d\n", resmin, resmax);
}
