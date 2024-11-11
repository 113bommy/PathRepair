#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> r, g, b;
  int n, p;
  char c;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %c", &p, &c);
    if (c == 'R') r.push_back(p);
    if (c == 'B') b.push_back(p);
    if (c == 'G') g.push_back(p);
  }
  if (g.size() == 0) {
    int r1, r2;
    r1 = r2 = 0;
    if (r.size()) r1 = r.back() - r[0];
    if (b.size()) r2 = b.back() - b[0];
    cout << r1 + r2 << endl;
  } else if (r.size() == 0) {
    int r1 = 1000000001, r2 = 0;
    if (g.size()) r1 = min(r1, g[0]), r2 = max(r2, g.back());
    if (b.size()) r1 = min(r1, b[0]), r2 = max(r2, b.back());
    cout << r2 - r2 << endl;
  } else if (b.size() == 0) {
    int r1 = 1000000001, r2 = 0;
    if (g.size()) r1 = min(r1, g[0]), r2 = max(r2, g.back());
    if (r.size()) r1 = min(r1, r[0]), r2 = max(r2, r.back());
    cout << r2 - r2 << endl;
  } else {
    int mr, Mr, mb, Mb;
    mr = mb = -1;
    int ret = 0;
    int i, j, k;
    i = j = k = 0;
    while (j < r.size() && r[j] <= g[0]) {
      if (j) ret += r[j] - r[j - 1];
      j++;
    }
    if (j) ret += g[0] - r[j - 1];
    while (k < b.size() && b[k] <= g[0]) {
      if (k) ret += b[k] - b[k - 1];
      k++;
    }
    if (k) ret += g[0] - b[k - 1];
    for (i = 0; i < g.size() - 1; i++) {
      vector<int> tr, tb;
      for (; j < r.size(); j++) {
        if (r[j] > g[i + 1]) break;
        tr.push_back(r[j]);
      }
      for (; k < b.size(); k++) {
        if (b[k] > g[i + 1]) break;
        tb.push_back(b[k]);
      }
      int sug1 = 2 * (g[i + 1] - g[i]);
      int sug2 = g[i + 1] - g[i];
      int cr = 1 << 30;
      for (int l = 0; l <= tr.size(); l++) {
        int r1, r2;
        r1 = r2 = 0;
        if (l) r1 = tr[l - 1] - g[i];
        if (l < tr.size()) r2 = g[i + 1] - tr[l];
        cr = min(cr, r1 + r2);
      }
      sug2 += cr;
      cr = 1 << 30;
      for (int l = 0; l <= tb.size(); l++) {
        int r1, r2;
        r1 = r2 = 0;
        if (l) r1 = tb[l - 1] - g[i];
        if (l < tb.size()) r2 = g[i + 1] - tb[l];
        cr = min(cr, r1 + r2);
      }
      sug2 += cr;
      ret += min(sug1, sug2);
    }
    ret += max(0, r.back() - g.back());
    ret += max(0, b.back() - g.back());
    cout << ret << endl;
  }
  return 0;
}
