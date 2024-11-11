#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 7;
int n, a[N], b[N], c[N], du[N];
int fir[N], from[N << 1], to[N << 1], cntt;
inline void add(int a, int b) {
  from[++cntt] = fir[a];
  fir[a] = cntt;
  to[cntt] = b;
}
int find(int x, int fa) {
  if (du[x] == 1) return x;
  for (int i = fir[x]; i; i = from[i])
    if (to[i] != fa) return find(to[i], x);
}
struct dat {
  int x, y, z;
  dat(int _x = 0, int _y = 0, int _z = 0) { x = _x, y = _y, z = _z; }
};
vector<dat> ans;
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    a[i] = read(), b[i] = read();
    c[i] = read();
    add(a[i], b[i]);
    add(b[i], a[i]);
    du[a[i]]++, du[b[i]]++;
  }
  if (n == 2) {
    printf("YES\n1\n1 2 %d\n", c[1]);
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (du[a[i]] == 2 || du[b[i]] == 2) {
      printf("NO\n");
      return 0;
    }
    if (du[b[i]] == 1) swap(a[i], b[i]);
    vector<int> L, R;
    for (int j = fir[a[i]]; j; j = from[j])
      if (to[j] != b[i]) L.push_back(find(to[j], a[i]));
    for (int j = fir[b[i]]; j; j = from[j])
      if (to[j] != a[i]) R.push_back(find(to[j], b[i]));
    if (L.size() == 0)
      ans.push_back(dat(a[i], R[0], c[i] / 2)),
          ans.push_back(dat(a[i], R[1], c[i] / 2)),
          ans.push_back(dat(R[0], R[1], -c[i] / 2));
    else
      ans.push_back(dat(L[0], R[0], c[i] / 2)),
          ans.push_back(dat(L[1], R[1], c[i] / 2)),
          ans.push_back(dat(L[0], L[1], -c[i] / 2)),
          ans.push_back(dat(R[0], R[1], -c[i] / 2));
  }
  printf("YES\n%d\n", int(ans.size()));
  for (auto A : ans) printf("%d %d %d\n", A.x, A.y, A.z);
  return 0;
}
