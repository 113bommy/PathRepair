#include <bits/stdc++.h>
using namespace std;
int n, m, k, r[10005], c[10005], rt[10005], cnt, up[10005], dn[10005],
    le[10005], ri[10005], root[10005], dist[10005], idst;
int mx[] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};
bool flag;
vector<int> v[10005];
int find_rt(int x) {
  if (rt[x] == x) return x;
  return rt[x] = find_rt(rt[x]);
}
bool cnct(int x, int y) {
  for (int t = 0; t < 4; t++) {
    if (make_pair(r[x] + my[t], c[x] + mx[t]) == make_pair(r[y], c[y]))
      return true;
  }
  return false;
}
void calc_rt() {
  flag = 0;
  for (int i = 0; i < k && !flag; i++) {
    if (r[i] == n && c[i] == m) {
      flag = 1;
      swap(r[i], r[k - 1]);
      swap(c[i], c[k - 1]);
    }
  }
  if (!flag) {
    r[k] = n + 1, c[k] = m + 1;
    k++;
  }
  for (int i = 0; i < k; i++) {
    up[i] = dn[i] = r[i];
    le[i] = ri[i] = c[i];
    rt[i] = i;
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      if (cnct(i, j)) rt[find_rt(i)] = find_rt(j);
    }
  }
  for (int i = 0; i < k; i++) {
    int x = find_rt(i);
    if (up[x] > r[i]) up[x] = r[i];
    if (dn[x] < r[i]) dn[x] = r[i];
    if (le[x] > c[i]) le[x] = c[i];
    if (ri[x] < c[i]) ri[x] = c[i];
  }
}
bool cango(int x, int y) {
  if (find_rt(x) == find_rt(y)) return true;
  x = find_rt(x), y = find_rt(y);
  if (le[x] > le[y]) return cango(y, x);
  if (ri[x] + 2 >= le[y]) return true;
  if (up[x] >= up[y] && up[x] - 2 <= dn[y] ||
      up[x] < up[y] && dn[x] + 2 >= up[y])
    return true;
  return false;
}
void calc_dist() {
  for (int i = 0; i < k; i++) dist[i] = 1000000007;
  queue<int> q;
  dist[idst] = 0, q.push(idst);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < k; i++) {
      if (cango(u, i) && dist[i] == 1000000007) {
        dist[i] = dist[u] + 1;
        q.push(i);
      }
    }
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &r[i], &c[i]);
    if (r[i] == 1 && c[i] == 1) idst = i;
  }
  calc_rt();
  calc_dist();
  if (find_rt(k - 1) == find_rt(idst))
    printf("0");
  else if (dist[k - 1] == 1000000007)
    printf("-1");
  else
    printf("%d", dist[k - 1]);
}
