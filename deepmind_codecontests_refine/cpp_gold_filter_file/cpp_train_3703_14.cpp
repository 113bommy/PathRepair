#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "{";
  for (const T &a : v) out << a << ", ";
  out << "}";
  return out;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n;
int other[200010];
int col[200010];
pair<int, int> pr[200010];
int nxt(int u) {
  u += 1;
  if (u == n) return 0;
  return u;
}
int nxtnxt(int u) {
  u += 2;
  if (u >= n) return u - n;
  return u;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    other[a] = b;
    other[b] = a;
    col[a] = (rand() % 2);
    col[b] = 1 - col[a];
    pr[i] = pair<int, int>(a, b);
  }
  n *= 2;
  bool err = 0;
  for (int rp = (0); rp < (1000); ++rp) {
    err = 0;
    for (int i = (0); i < (n); ++i) {
      int u = i;
      int v = nxt(i);
      int w = nxtnxt(i);
      if (col[u] == col[v] && col[v] == col[w]) {
        err = 1;
        int r = rand() % 3;
        if (r == 1)
          u = v;
        else if (r == 2)
          u = w;
        col[u] = 1 - col[u];
        col[other[u]] = 1 - col[u];
      }
    }
    if (!err) break;
  }
  if (err) {
    printf("-1\n");
  } else {
    n /= 2;
    for (int i = (0); i < (n); ++i)
      printf("%d %d\n", col[pr[i].first] + 1, col[pr[i].second] + 1);
  }
  return 0;
}
