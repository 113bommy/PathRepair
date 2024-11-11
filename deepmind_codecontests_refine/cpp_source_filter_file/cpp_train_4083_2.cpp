#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e6) + 5;
const int IT_MAX = 1 << 20;
const int INF = -1;
int bit[IT_MAX + 10];
void update(int p, int dv) {
  for (; p <= IT_MAX; p += p & (-p)) bit[p] += dv;
}
int query(int p) {
  int rv = 0;
  for (; p; p -= p & (-p)) rv += bit[p];
  return rv;
}
int largerpos(int v) {
  if (bit[IT_MAX] <= v) return INF;
  int p = 0;
  int s = 0;
  for (int i = 17; i >= 0; i--) {
    if (s + bit[p + (1 << i)] <= v) {
      s += bit[p + (1 << i)];
      p |= (1 << i);
    }
  }
  return p + 1;
}
vector<int> st[MAX], en[MAX];
int l[MAX], r[MAX];
int pa[MAX], sz[MAX];
int finPa(int p) { return pa[p] == p ? p : pa[p] = finPa(pa[p]); }
bool mergeNode(int u, int v) {
  int r1 = finPa(u), r2 = finPa(v);
  if (sz[r1] < sz[r2]) {
    swap(r1, r2);
  }
  pa[r2] = r1;
  sz[r1] += sz[r2];
  return (r1 == r2);
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 1; i <= MAX; i++) {
    sz[i] = 1;
    pa[i] = i;
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    st[l[i]].push_back(i);
    en[r[i]].push_back(i);
  }
  for (int i = 1; i <= 2 * n; i++) {
    for (int s : st[i]) {
      update(l[s], 1);
    }
    for (int s : en[i]) {
      int nex = largerpos(query(l[s]));
      while (nex != -1) {
        for (int ns : st[nex]) {
          if (mergeNode(s, ns)) {
            cout << "NO" << endl;
            return 0;
          }
        }
        nex = largerpos(query(nex));
      }
    }
    for (int s : en[i]) {
      update(l[s], -1);
    }
  }
  int p = finPa(1);
  cout << ((sz[p] == n) ? "YES" : "NO") << endl;
  return 0;
}
