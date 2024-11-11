#include <bits/stdc++.h>
using namespace std;
int subCount(int wc[256], int sc[256]) {
  int c = 10000000;
  for (int i = 0; i < 256; i++) {
    if (sc[i] > wc[i]) {
      return 0;
    }
    if (sc[i] != 0) {
      int cc = wc[i] / sc[i];
      if (cc < c) c = cc;
    }
  }
  return c;
}
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  int cc[256], ccb[256], ccc[256], n = a.size(), nb = b.size(), nc = c.size();
  fill(cc, cc + 256, 0);
  fill(ccb, ccb + 256, 0);
  fill(ccc, ccc + 256, 0);
  for (int i = 0; i < n; i++) {
    cc[a[i]]++;
  }
  for (int i = 0; i < nb; i++) {
    ccb[b[i]]++;
  }
  for (int i = 0; i < nc; i++) {
    ccc[c[i]]++;
  }
  int maxit = 0, maxid = -1, maxidd = -1;
  int nn = min(nb, nc);
  for (int i = 0; i <= n / nn; i++) {
    int sc = subCount(cc, ccb);
    if (i > sc) break;
    int cccc[256];
    for (int j = 0; j < 256; j++) {
      cccc[j] = cc[j] - i * ccb[j];
    }
    int scc = subCount(cccc, ccc);
    int t = i + scc;
    if (t > maxit) {
      maxit = t;
      maxid = i;
      maxidd = scc;
    }
  }
  if (maxid != -1) {
    for (int i = 0; i < maxid; i++) {
      cout << b;
    }
    for (int i = 0; i < maxidd; i++) {
      cout << c;
    }
    for (int i = 0; i < 256; i++) {
      cc[i] -= maxid * ccb[i] + maxidd * ccc[i];
    }
  }
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < cc[i]; j++) {
      cout << char(i);
    }
  }
  cout << endl;
  return 0;
}
