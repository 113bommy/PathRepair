#include <bits/stdc++.h>
using namespace std;
struct node {
  int cn;
  long long sm[5];
} tr[(100000 << 3) + 100];
void update(int p, int v, int m, int op, int st, int fn) {
  if (st == fn) {
    if (op == 1) {
      tr[p].sm[0] += v;
      tr[p].cn++;
    } else {
      tr[p].sm[0] -= v;
      tr[p].cn--;
    }
    return;
  }
  int md = (st + fn) >> 1, lf = (p << 1) + 1, rt = lf + 1;
  if (m <= md)
    update(lf, v, m, op, st, md);
  else
    update(rt, v, m, op, md + 1, fn);
  md = tr[lf].cn % 5;
  int i;
  for (i = 0; i < 5; i++) tr[p].sm[i] = tr[lf].sm[i] + tr[rt].sm[(i + md) % 5];
  tr[p].cn = tr[p].cn + op;
}
pair<string, int> qr[100000 + 10];
map<int, int> M;
int main() {
  char wd[10];
  int n, i, u, L;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%s", wd);
    if (wd[0] != 's') {
      scanf("%d", &u);
      M[u] = 0;
      qr[i] = make_pair(string(wd), u);
    } else
      qr[i] = make_pair(string(wd), 0);
  }
  i = 1;
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
    it->second = i++;
  }
  L = i;
  for (i = 0; i < n; i++) {
    if (qr[i].first[0] == 's') {
      printf("%I64dd\n", tr[0].sm[3]);
    } else {
      update(0, qr[i].second, M[qr[i].second], qr[i].first[0] == 'a' ? 1 : -1,
             1, n);
    }
  }
  return 0;
}
