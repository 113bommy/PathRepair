#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int x[N], y[N], c[N], vt[N], st[N];
int n;
bool mark[N];
vector<pair<int, int>> res;
inline bool cmp(int i, int j) {
  return (x[i] - x[vt[0]]) * (y[j] - y[vt[0]]) >
         (x[j] - x[vt[0]]) * (y[i] - y[vt[0]]);
}
inline bool good(int i, int j, int k) {
  return (x[j] - x[i]) * (y[k] - y[j]) > (x[k] - x[j]) * (y[j] - y[i]);
}
inline bool check_in(int z, int i, int j, int k) {
  if (z == i || z == j || z == k) return false;
  bool save = good(i, j, z);
  if (save != good(j, k, z)) return false;
  return save == good(k, i, z);
}
void solve(int i, int j, int k) {
  int cc = c[i] ^ c[j] ^ c[k];
  if (c[j] == cc) swap(i, j);
  if (c[k] == cc) swap(i, k);
  int found = -1;
  for (int z = 0; z < n; z++) {
    mark[z] = check_in(z, i, j, k);
    if (!mark[z]) continue;
    if (c[z] == cc) {
      found = z;
      break;
    }
  }
  if (found >= 0) {
    res.push_back(make_pair(i, found));
    solve(found, j, k);
    solve(j, i, found);
    solve(k, i, found);
  } else {
    for (int z = 0; z < n; z++)
      if (mark[z]) res.push_back(make_pair(j, z));
  }
}
int main() {
  scanf("%d", &n);
  int c0 = 0, c1 = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", x + i, y + i, c + i);
    if (c[i] == 0)
      c0++;
    else
      c1++;
    vt[i] = i;
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  if (c0 == n || c1 == n) {
    printf("%d\n", n - 1);
    for (int i = 1; i < n; i++) printf("0 %d\n", i);
    return 0;
  }
  int neo = 0;
  for (int i = 1; i < n; i++)
    if (y[i] < y[neo]) neo = i;
  if (neo > 0) swap(vt[0], vt[neo]);
  sort(vt + 1, vt + n, cmp);
  int top = -1;
  st[++top] = vt[0];
  for (int i = 1; i < n; i++) {
    while (top - 1 >= 0 && !good(st[top - 1], st[top], vt[i])) top--;
    st[++top] = vt[i];
  }
  int dem = 1;
  for (int i = 1; i <= top; i++)
    if (c[st[i]] != c[st[i - 1]]) dem++;
  if (dem > 3) {
    puts("Impossible");
    return 0;
  }
  if (dem == 1) {
    for (int i = 1; i <= top; i++) res.push_back(make_pair(st[i - 1], st[i]));
    int cc = c[st[0]] ^ 1;
    for (int i = 0; i < n; i++)
      if (c[i] == cc) {
        for (int j = 0; j <= top; j++) {
          int k = j - 1;
          if (j == 0) k = top;
          solve(i, st[k], st[j]);
        }
        break;
      }
  } else {
    dem = 1;
    int last0 = -1, last1 = -1;
    for (int i = 0; i <= top; i++) {
      int j = i - 1;
      if (i == 0) j = top;
      if (c[st[i]] == c[st[j]]) res.push_back(make_pair(st[i], st[j]));
      if (i > 0 && c[st[i]] != c[st[i - 1]]) dem++;
      if (dem == 1)
        last0 = i;
      else if (dem == 2)
        last1 = i;
    }
    int u = last0 + 1;
    while (u != last1) {
      solve(st[last0], st[u], st[u + 1]);
      u++;
    }
    u = last1 + 1;
    if (u > top) u = 0;
    while (u != last0) {
      int v = u + 1;
      if (v > top) v = 0;
      solve(st[last1], st[u], st[v]);
      u = v;
    }
  }
  printf("%d\n", res.size());
  for (auto &p : res) printf("%d %d\n", p.first, p.second);
}
