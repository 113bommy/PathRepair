#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 100;
int ats[MAX_N], dfs[MAX_N], bs[MAX_M];
bool used[MAX_M];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int an = 0, dn = 0;
  for (int i = 0; i < n; i++) {
    char s[8];
    int x;
    scanf("%s%d", s, &x);
    if (s[0] == 'A')
      ats[an++] = x;
    else
      dfs[dn++] = x;
  }
  for (int i = 0; i < m; i++) scanf("%d", bs + i);
  sort(ats, ats + an);
  sort(dfs, dfs + dn);
  sort(bs, bs + m);
  int maxsum = 0;
  for (int k = 0; k < an; k++) {
    int sum = 0;
    bool ok = true;
    for (int i = k, j = m - 1; i >= 0 && j >= 0; i--, j--) {
      if (ats[i] <= bs[j])
        sum += bs[j] - ats[i];
      else {
        ok = false;
        break;
      }
    }
    if (!ok) break;
    if (maxsum < sum) maxsum = sum;
  }
  if (n < m) {
    bool ok = true;
    for (int i = 0, j = 0; i < dn; i++) {
      while (j < m && dfs[i] >= bs[j]) j++;
      if (j < m)
        used[j++] = true;
      else {
        ok = false;
        break;
      }
    }
    if (ok) {
      int sum = 0;
      for (int j = m - 1, i = an - 1; j >= 0; j--)
        if (!used[j]) {
          if (ats[i] <= bs[j])
            sum += bs[j] - ats[i++];
          else {
            ok = false;
            break;
          }
        }
      if (ok && maxsum < sum) maxsum = sum;
    }
  }
  printf("%d\n", maxsum);
  return 0;
}
