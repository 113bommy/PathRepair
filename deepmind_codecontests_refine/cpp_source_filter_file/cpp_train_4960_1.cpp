#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 17;
int N, root[maxn], sz[maxn];
long long minv, maxv, val[maxn];
vector<int> tree[maxn];
vector<pair<long long, int> > nodes;
int find(int x) {
  if (root[x] == x) return x;
  return root[x] = find(root[x]);
}
long long merge(int first, int second) {
  int x = find(first), y = find(second);
  if (x == y) return 0LL;
  long long res = sz[x] * sz[y] * val[first];
  sz[x] += sz[y];
  root[y] = x;
  return res;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%I64d", val + i), nodes.push_back(make_pair(val[i], i));
  for (int i = 1; i < N; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    tree[A].push_back(B);
    tree[B].push_back(A);
  }
  sort(nodes.begin(), nodes.end());
  for (int i = 1; i <= N; i++) root[i] = i, sz[i] = 1;
  for (int i = 0; i < N; i++)
    for (int v : tree[nodes[i].second])
      if (val[nodes[i].second] >= val[v]) maxv += merge(nodes[i].second, v);
  for (int i = 1; i <= N; i++) root[i] = i, sz[i] = 1;
  for (int i = N - 1; i >= 0; i--)
    for (int v : tree[nodes[i].second])
      if (val[nodes[i].second] <= val[v]) minv += merge(nodes[i].second, v);
  printf("%I64d\n", maxv - minv);
  return 0;
}
