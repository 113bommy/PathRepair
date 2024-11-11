#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
string s;
int n;
int ldat[2 * maxn - 1], rdat[2 * maxn - 1], legaldat[2 * maxn - 1];
typedef struct Data {
  int l;
  int r;
  int legal;
};
void init(int n_) {
  n = 1;
  while (n < n_) n *= 2;
  memset(ldat, 0, sizeof(ldat));
  memset(rdat, 0, sizeof(rdat));
  memset(legaldat, 0, sizeof(legaldat));
}
void update(int k, char a) {
  k += n - 1;
  if (a == ')') {
    ldat[k] = 1;
    rdat[k] = 0;
    legaldat[k] = 0;
  } else {
    ldat[k] = 0;
    rdat[k] = 1;
    legaldat[k] = 0;
  }
  while (k > 0) {
    k = (k - 1) / 2;
    legaldat[k] = legaldat[k * 2 + 1] + legaldat[k * 2 + 2];
    if (rdat[k * 2 + 1] > ldat[k * 2 + 2]) {
      legaldat[k] += 2 * ldat[k * 2 + 2];
      rdat[k] = rdat[k * 2 + 1] - ldat[k * 2 + 2] + rdat[k * 2 + 2];
      ldat[k] = ldat[k * 2 + 1];
    } else {
      legaldat[k] += 2 * rdat[k * 2 + 1];
      ldat[k] = ldat[k * 2 + 2] - rdat[k * 2 + 1] + ldat[k * 2 + 1];
      rdat[k] = rdat[k * 2 + 2];
    }
  }
}
void build() {
  for (int i = 0; i < s.length(); i++) {
    update(i, s[i]);
  }
}
Data query(int a, int b, int k, int l, int r) {
  Data dat;
  dat.l = 0;
  dat.legal = 0;
  dat.r = 0;
  if (r < a || b < l) return dat;
  if (a <= l && r <= b) {
    dat.l = ldat[k];
    dat.legal = legaldat[k];
    dat.r = rdat[k];
    return dat;
  } else {
    Data v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Data v2 = query(a, b, k * 2 + 2, (l + r) / 2 + 1, r);
    dat.legal = v1.legal + v2.legal;
    if (v1.r > v2.l) {
      dat.legal += 2 * v2.l;
      dat.r = v1.r - v2.l + v2.r;
      dat.l = v1.l;
    } else {
      dat.legal += 2 * v1.r;
      dat.l = v2.l - v1.r + v1.l;
      dat.r = v2.r;
    }
    return dat;
  }
}
int main() {
  int m;
  cin >> s;
  init(s.length());
  build();
  int i;
  cin >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    printf("%d\n", query(l - 1, r - 1, 0, 0, n - 1).legal);
  }
  return 0;
}
