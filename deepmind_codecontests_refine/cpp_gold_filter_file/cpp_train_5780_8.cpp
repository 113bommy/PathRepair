#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge {
  int w, id;
} in[N], out[N];
bool cmp(edge a, edge b) { return a.w < b.w; }
int inlen, outlen, n, m, ans[N][2], pt[N];
int idx(int w) {
  int l = 0, r = inlen;
  while (l < r) {
    int M = (l + r) / 2;
    if (in[M].w <= w)
      l = M + 1;
    else
      r = M;
  }
  return l;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int w, con;
    scanf("%d%d", &w, &con);
    if (con) {
      in[inlen].w = w;
      in[inlen++].id = i;
    } else {
      out[outlen].w = w;
      out[outlen++].id = i;
    }
  }
  sort(in, in + inlen, cmp);
  sort(out, out + outlen, cmp);
  for (int i = 0; i < inlen; i++) {
    ans[in[i].id][0] = 1;
    ans[in[i].id][1] = i + 2;
  }
  bool yes = 1;
  for (int i = 0; i < outlen; i++) {
    int id = idx(out[i].w);
    if (id == inlen) id--;
    while (in[id].w > out[i].w && id >= 0) id--;
    if (id < 0) {
      yes = 0;
      break;
    }
    while (pt[id] >= id && id >= 0) id--;
    if (id < 0) {
      yes = 0;
      break;
    }
    ans[out[i].id][0] = ans[in[id].id][1];
    ans[out[i].id][1] = ans[in[pt[id]++].id][1];
  }
  if (yes) {
    for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  } else {
    puts("-1");
  }
  return 0;
}
