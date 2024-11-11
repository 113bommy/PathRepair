#include <bits/stdc++.h>
using namespace std;
int T;
long long n1, n2, n3, m1, m2, m3, s1, s2, s3, n, m, s;
vector<pair<int, int> > vn, vm, vs;
int a[1005];
long long ans;
vector<pair<int, int> > v;
vector<pair<int, int> > divi(long long p1, long long p2, long long p3) {
  vector<pair<int, int> > ret;
  ret.clear();
  long long op[3];
  op[0] = p1;
  op[1] = p2;
  op[2] = p3;
  a[0] = 0;
  for (int i = 0; i <= 2; i++) {
    long long now = op[i];
    for (long long j = 2; j * j <= now; j++) {
      if (now == 1) break;
      if (now % j == 0) {
        while (now % j == 0) {
          a[++a[0]] = j;
          now = now / j;
        }
      }
    }
    if (now != 1) a[++a[0]] = now;
  }
  sort(a + 1, a + a[0] + 1);
  int siz = 0;
  for (int i = 1; i <= a[0]; i++) {
    if (i == 1 || a[i] != a[i - 1]) {
      ret.push_back(make_pair(a[i], 1));
      siz++;
    } else
      ret[siz - 1].second++;
  }
  return ret;
}
void dfs(int wz, long long mx) {
  if (wz == vs.size()) {
    if (mx <= n) ans++;
    return;
  }
  long long tmp = 1;
  for (int i = 0; i <= vs[wz].second; i++) {
    dfs(wz + 1, mx * tmp);
    tmp = tmp * vs[wz].first;
  }
}
void dfs_new(int wz, long long mx, int cho) {
  if (mx == 0) return;
  if (wz == v.size()) {
    ans += cho * mx;
    return;
  }
  dfs_new(wz + 1, mx, cho);
  long long tmp = 1;
  for (int i = 0; i <= v[wz].second; i++) tmp = tmp * v[wz].first;
  dfs_new(wz + 1, mx / tmp, -cho);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    vn.clear();
    vm.clear();
    vs.clear();
    cin >> n1 >> n2 >> n3 >> m1 >> m2 >> m3 >> s1 >> s2 >> s3;
    s1 = s1 * 2;
    n = n1 * n2 * n3;
    m = m1 * m2 * m3;
    s = s1 * s2 * s3;
    vn = divi(n1, n2, n3);
    vm = divi(m1, m2, m3);
    vs = divi(s1, s2, s3);
    dfs(0, 1);
    v.clear();
    int z1 = 0, z2 = 0, p1 = vn.size() - 1, p2 = vs.size() - 1;
    while (z1 <= p1 && z2 <= p2) {
      if (vn[z1].first == vs[z2].first) {
        if (vn[z1].second > vs[z2].second) {
          v.push_back(vs[z2]);
        }
        z1++;
        z2++;
      } else if (vn[z1].first < vn[z2].first) {
        v.push_back(make_pair(vn[z1].first, 0));
        z1++;
      } else {
        z2++;
      }
    }
    while (z1 <= p1) {
      v.push_back(make_pair(vn[z1].first, 0));
      z1++;
    }
    dfs_new(0, m, 1);
    cout << ans << endl;
  }
  return 0;
}
