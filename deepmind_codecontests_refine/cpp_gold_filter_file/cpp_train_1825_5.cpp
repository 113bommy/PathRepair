#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic warning "-Wconversion"
using ll = long long;
char nc[200007], mc[200007];
ll ni[200007], mi[200007];
int skip[200007];
int main() {
  int n, m;
  cin >> n >> m;
  int idx = 0;
  int del = 0;
  for (int i = 0; i < n; i++) {
    char pc;
    int pi;
    scanf("%d-%c", &pi, &pc);
    if (idx > 0 && pc == nc[idx - 1]) {
      ni[idx - 1] += pi;
      del++;
    } else {
      nc[idx] = pc;
      ni[idx] = pi;
      idx++;
    }
  }
  n -= del;
  idx = 0, del = 0;
  for (int i = 0; i < m; i++) {
    char pc;
    int pi;
    scanf("%d-%c", &pi, &pc);
    if (idx > 0 && pc == mc[idx - 1]) {
      mi[idx - 1] += pi;
      del++;
    } else {
      mc[idx] = pc;
      mi[idx] = pi;
      idx++;
    }
  }
  m -= del;
  if (m == 1) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (nc[i] != mc[0]) continue;
      res += max(0LL, ni[i] - mi[0] + 1);
    }
    cout << res << endl;
    return 0;
  }
  int pos = 0;
  int len = -1;
  skip[pos] = -1;
  while (pos < m - 2) {
    while ((len >= 0) &&
           (mc[pos + 1] != mc[len + 1] || mi[pos + 1] != mi[len + 1]))
      len = skip[len];
    ++len;
    ++pos;
    skip[pos] = len;
  }
  ll posS = 0, posT = 0;
  ll res = 0;
  while (posS < n) {
    while ((posT >= 0) &&
           (nc[posS] != mc[posT + 1] || ni[posS] != mi[posT + 1]))
      posT = skip[posT];
    posS++;
    posT++;
    if (posT == m - 2) {
      ll found = posS - (m - 2);
      if (found > 0 && found + (m - 2) < n && nc[found - 1] == mc[0] &&
          ni[found - 1] >= mi[0] && nc[found + m - 2] == mc[m - 1] &&
          ni[found + m - 2] >= mi[m - 1])
        res++;
      posT = skip[posT];
    }
  }
  cout << res << endl;
}
