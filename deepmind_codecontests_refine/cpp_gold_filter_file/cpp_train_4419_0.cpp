#include <bits/stdc++.h>
using namespace std;
int visr[1005], vist[1005];
vector<int> rr, rt;
struct req {
  int c, p, pr;
} r[1005];
bool cmp1(req a, req b) {
  if (a.p != b.p) return a.p > b.p;
  return a.c < b.c;
}
struct tbl {
  int rr, pt;
} t[1005];
bool cmp2(tbl c, tbl d) { return c.rr < d.rr; }
int main() {
  int n;
  int i, j, k, sum, tk;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &r[i].c, &r[i].p);
    r[i].pr = i + 1;
    visr[i] = 0;
  }
  sort(r, r + n, cmp1);
  scanf("%d", &k);
  for (j = 0; j < k; j++) {
    scanf("%d", &t[j].rr);
    t[j].pt = j + 1;
    vist[j] = 0;
  }
  sort(t, t + k, cmp2);
  tk = sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      if (r[i].c <= t[j].rr && !visr[i] && !vist[j]) {
        tk++;
        sum += r[i].p;
        visr[i] = vist[j] = 1;
        rr.push_back(r[i].pr), rt.push_back(t[j].pt);
      }
    }
  }
  printf("%d %d\n", tk, sum);
  for (i = 0; i < tk; i++) cout << rr[i] << " " << rt[i] << "\n";
  return 0;
}
