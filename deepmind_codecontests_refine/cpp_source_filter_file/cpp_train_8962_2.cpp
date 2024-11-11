#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long sc[300001][2];
long long d[300001];
long long best[300001], w[300001];
vector<long long> hate[300001];
long long aa[300001], bb[300001];
long long prefixa[300001], prefixb[300001];
long long cnta = 0, cntb = 0;
long long work(long long d, long long val) {
  long long ret = 0;
  if (d == 1) {
    long long lo = 1, hi = cnta + 1, m;
    while (lo < hi) {
      m = (lo + hi) / 2;
      if (aa[m] <= val)
        lo = m + 1;
      else
        hi = m;
    }
    ret += prefixa[lo - 1];
    ret += val * (n - lo);
  } else {
    long long lo = 1, hi = cntb + 1, m;
    while (lo < hi) {
      m = (lo + hi) / 2;
      if (bb[m] <= val)
        lo = m + 1;
      else
        hi = m;
    }
    ret += prefixb[lo - 1];
    ret += val * (n - lo);
  }
  return ret;
}
int main() {
  long long sb = 0;
  long long i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    long long inputx, inputy;
    scanf("%lld", &inputx);
    scanf("%lld", &inputy);
    sc[i][0] = inputx, sc[i][1] = inputy;
    best[i] = min(inputx, inputy);
    w[i] = max(inputx, inputy) - best[i];
    if (inputx > inputy)
      d[i] = 1, aa[++cnta] = w[i];
    else
      bb[++cntb] = w[i];
  }
  for (i = 1; i <= m; i++) {
    long long inputx, inputy;
    scanf("%lld", &inputx);
    scanf("%lld", &inputy);
    hate[inputx].push_back(inputy);
    hate[inputy].push_back(inputx);
  }
  sort(bb + 1, bb + cntb + 1);
  sort(aa + 1, aa + cnta + 1);
  for (i = 1; i <= n; i++) sb += best[i];
  for (i = 1; i <= cnta; i++) prefixa[i] = prefixa[i - 1] + aa[i];
  for (i = 1; i <= cntb; i++) prefixb[i] = prefixb[i - 1] + bb[i];
  for (i = 1; i <= n; i++) {
    long long ans = 0;
    ans += sb;
    ans += best[i] * (n - 2);
    ans += work(d[i], w[i]);
    for (j = 0; j < hate[i].size(); j++) {
      long long f = hate[i][j];
      if (d[i] != d[f])
        ans -= best[i] + best[f];
      else
        ans -= best[i] + best[f] + min(w[i], w[f]);
    }
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
