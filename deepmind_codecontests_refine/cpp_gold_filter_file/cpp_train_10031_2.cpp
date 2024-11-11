#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int f, s, i;
} hehe;
hehe qry[100009];
int f[100009];
int a[100009], b[100009], vans[100009], c[100009];
int bsz;
map<int, int> m;
bool comp(hehe a, hehe b) {
  if (a.f / bsz != b.f / bsz) return a.f / bsz < b.f / bsz;
  return a.s < b.s;
}
void mos(int n, int mq) {
  bsz = static_cast<int>(floor(sqrt(n)));
  sort(qry, qry + mq, comp);
  int cr = 0, cl = 0, ans = 0;
  for (int i = 0; i < mq; i++) {
    int l = qry[i].f;
    int r = qry[i].s;
    while (cl < l) {
      f[a[cl]]--;
      if (f[a[cl]] == c[cl] - 1) ans--;
      if (f[a[cl]] == c[cl]) ans++;
      cl++;
    }
    while (cl > l) {
      cl--;
      f[a[cl]]++;
      if (f[a[cl]] == c[cl]) ans++;
      if (f[a[cl]] == c[cl] + 1) ans--;
    }
    while (cr <= r) {
      f[a[cr]]++;
      if (f[a[cr]] == c[cr]) ans++;
      if (f[a[cr]] == c[cr] + 1) ans--;
      cr++;
    }
    while (cr > r + 1) {
      cr--;
      f[a[cr]]--;
      if (f[a[cr]] == c[cr] - 1) ans--;
      if (f[a[cr]] == c[cr]) ans++;
    }
    vans[qry[i].i] = ans;
  }
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = c[i] = a[i];
  }
  sort(b, b + n);
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (i > 0 && b[i] == b[i - 1]) continue;
    m[b[i]] = cnt++;
  }
  for (int i = 1; i <= n; i++) a[i] = m[a[i]];
  for (int i = 0; i < q; i++) cin >> qry[i].f >> qry[i].s, qry[i].i = i;
  mos(n, q);
  for (int i = 0; i < q; i++) cout << vans[i] << endl;
}
