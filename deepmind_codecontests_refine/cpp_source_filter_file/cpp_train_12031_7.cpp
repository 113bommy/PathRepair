#include <bits/stdc++.h>
using namespace std;
long long n, alen, bob, shu;
int a[100009][3], b[100009][3], zhi[100009][3];
struct cmp {
  int zpl, z, hao;
  bool operator<(const cmp &aa) const { return aa.z > z; }
};
priority_queue<cmp> Q;
int main() {
  cmp u;
  scanf("%d", &n);
  for (int q = 1; q <= n; q++) {
    scanf("%d%d%d%d", &a[q][1], &b[q][1], &a[q][2], &b[q][2]);
    zhi[q][1] = a[q][1] + b[q][1];
    zhi[q][2] = a[q][2] + b[q][2];
  }
  for (int q = 1; q <= n; q++) {
    if (zhi[q][1] > zhi[q][2]) {
      u.zpl = 1;
      u.z = zhi[q][1];
      u.hao = q;
      Q.push(u);
    } else {
      if (a[q][1] > b[q][2]) alen += a[q][1], bob += b[q][2];
      if (b[q][1] > a[q][2]) bob += b[q][q], alen += a[q][2];
    }
  }
  while (!Q.empty()) {
    shu++;
    u = Q.top();
    Q.pop();
    if (shu % 2 == 1)
      alen += u.z - b[u.hao][u.zpl];
    else
      bob += u.z - a[u.hao][u.zpl];
    if (u.zpl == 1) {
      u.z = zhi[u.hao][2];
      u.zpl = 2;
      Q.push(u);
    }
  }
  cout << alen - bob;
}
