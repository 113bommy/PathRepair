#include <bits/stdc++.h>
using namespace std;
int maximum(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
bool cmp(const pair<int, int>& firs, const pair<int, int>& sec) {
  if (firs.second != sec.second)
    return firs.second > sec.second;
  else
    return firs.first < sec.first;
}
struct node {
  int x;
  int y;
};
struct node1 {
  int u;
  int v;
  int w;
};
node1 out[1005] = {0};
node in[1005] = {0};
bool cmp1(const node& firs, const node& sec) { return firs.x < sec.y; }
bool cmp2(const node1& firs, const node1& sec) {
  if (firs.v != sec.v)
    return firs.v > sec.v;
  else
    return firs.u < sec.u;
}
int main() {
  int n, a, b, i, k;
  scanf("%d", &n);
  vector<pair<int, int> > v1;
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    out[i].u = a;
    out[i].v = b;
    out[i].w = i + 1;
  }
  scanf("%d", &k);
  for (i = 0; i < k; i++) scanf("%d", &in[i].x), in[i].y = i + 1;
  sort(in, in + k, cmp1);
  int ans = 0;
  sort(out, out + n, cmp2);
  int idx, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      if (in[j].x >= out[i].u) {
        ans += out[i].v;
        v1.push_back(make_pair(out[i].w, in[j].y));
        in[j].x = -1;
        break;
      }
    }
  }
  int l = v1.size();
  printf("%d %d\n", l, ans);
  for (i = 0; i < l; i++) {
    cout << v1[i].first << " " << v1[i].second << endl;
  }
  return 0;
}
