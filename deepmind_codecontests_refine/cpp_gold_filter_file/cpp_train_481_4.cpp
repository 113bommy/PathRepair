#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 9;
const int Mod = 1000000007;
struct Node {
  long long l, r, type;
  Node(long long x = 0, long long y = 0, long long z = 0) {
    l = x;
    r = y;
    type = z;
  }
} save[N];
struct M {
  long long a[3][3];
  M() {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) a[i][j] = 0;
  }
  void ones() {
    for (int i = 0; i < 3; i++) a[i][i] = 1;
  }
};
M operator*(M x, M y) {
  M res;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        res.a[i][j] += x.a[i][k] * y.a[k][j];
        res.a[i][j] %= Mod;
      }
    }
  }
  return res;
}
long long n, m;
vector<long long> pos;
int f[N * 2][3];
int main() {
  scanf("%I64d", &n);
  scanf("%I64d", &m);
  pos.push_back(1);
  pos.push_back(m);
  for (int i = 0; i < n; i++) {
    scanf("%I64d%I64d%I64d", &save[i].type, &save[i].l, &save[i].r);
    save[i].type--;
    pos.push_back(save[i].l);
    pos.push_back(save[i].r + 1);
  }
  sort(pos.begin(), pos.end());
  pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
  for (int i = 0; i < n; i++) {
    int p = lower_bound(pos.begin(), pos.end(), save[i].l) - pos.begin();
    f[p][save[i].type]++;
    p = lower_bound(pos.begin(), pos.end(), save[i].r + 1) - pos.begin();
    f[p][save[i].type]--;
  }
  M res;
  res.ones();
  long long g[3];
  g[0] = g[1] = g[2] = 0;
  for (int i = 0; i < (int)pos.size() - 1; i++) {
    M tmp;
    for (int j = 0; j < 3; j++) g[j] += f[i][j];
    if (!g[0]) tmp.a[0][1] = tmp.a[0][0] = 1;
    if (!g[1]) tmp.a[1][0] = tmp.a[1][2] = tmp.a[1][1] = 1;
    if (!g[2]) tmp.a[2][2] = tmp.a[2][1] = 1;
    long long b = pos[i + 1] - pos[i];
    while (b) {
      if (b & 1ll) res = res * tmp;
      tmp = tmp * tmp;
      b >>= 1ll;
    }
  }
  cout << res.a[1][1] << endl;
}
