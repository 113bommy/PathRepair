#include <bits/stdc++.h>
using namespace std;
const int MX = 2 * 1e5 + 10;
const double PI = acos(-1.0), EPS = 1e-9;
long long N, M;
struct data {
  int val, idx;
  data(int v = 0, int i = 0) {
    val = v;
    idx = i;
  }
  bool operator<(const data &d) const {
    if (val == d.val) return idx < d.idx;
    return val < d.val;
  }
};
data d[MX];
int p[MX], sz[MX], RmaxQ[MX], RminQ[MX], arr[MX];
int f(int x) {
  if (x == p[x]) return x;
  return p[x] = f(p[x]);
}
void Union(int x, int y) {
  x = f(x);
  y = f(y);
  if (x == y) return;
  if (sz[x] > sz[y]) swap(x, y);
  p[x] = y;
  sz[y] += sz[x];
  RminQ[y] = min(RminQ[y], RminQ[x]);
  RmaxQ[y] = max(RmaxQ[y], RmaxQ[x]);
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &d[i].val);
    d[i].idx = i;
    arr[i] = d[i].val;
    RminQ[i] = 1e9 + 10;
    RmaxQ[i] = -1e9 - 10;
    sz[i] = 1;
    p[i] = -1;
  }
  sort(d, d + N);
  for (int i = 0; i < N; i++) {
    int j = d[i].idx;
    if (p[j] != -1) continue;
    p[j] = j;
    RminQ[j] = arr[j];
    RmaxQ[j] = arr[j];
    j--;
    while (j >= 0) {
      if (p[j] != -1) {
        if (RminQ[p[j + 1]] >= RmaxQ[p[j]]) break;
        Union(j, j + 1);
        j--;
        continue;
      }
      p[j] = j;
      RminQ[j] = arr[j];
      RmaxQ[j] = arr[j];
      Union(j, j + 1);
      j--;
    }
  }
  set<int> com;
  for (int i = 0; i < N; i++) {
    com.insert(p[i]);
  }
  cout << com.size() << "\n";
  return 0;
}
