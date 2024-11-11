#include <bits/stdc++.h>
struct Quack {
  int l, r, ind;
  bool operator<(const Quack &aux) const { return aux.r < r; }
} v[1 + 100];
bool cmp(Quack A, Quack B) { return A.l < B.l; }
int ans[1 + 100];
std::priority_queue<Quack> pq;
int main() {
  FILE *fi, *fo;
  fi = stdin;
  fo = stdout;
  int n;
  fscanf(fi, "%d", &n);
  for (int i = 1; i <= n; i++)
    fscanf(fi, "%d%d", &v[i].l, &v[i].r), v[i].ind = i;
  std::sort(v + 1, v + n + 1, cmp);
  for (int i = 1; i <= n;) {
    int j = i + 1, t = v[i].l;
    pq.push(v[i]);
    while (j <= n && v[j].l == v[i].l) pq.push(v[j]), j++;
    while (!pq.empty()) {
      int node = pq.top().ind;
      pq.pop();
      ans[node] = t++;
      while (j <= n && v[j].l == t) pq.push(v[j]), j++;
    }
    i = j;
  }
  for (int i = 1; i <= n; i++) fprintf(fo, "%d ", ans[i]);
  return 0;
}
