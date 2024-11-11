#include <bits/stdc++.h>
using namespace std;
const int N = 194600;
const int MAX = 5032109;
const int Q = 1049660;
int lp[MAX];
int occ[MAX][10];
int n, q, a[N];
int fac[10], sz;
int cnt_used, brute_id;
int vis[N][20];
int wwww[MAX];
void brute_add(int i, int num) {
  if (i == sz) {
    for (int j = 0; j < 10; j++) {
      if (occ[num][j] == -1) continue;
      int &tmp = vis[occ[num][j]][sz - cnt_used + j];
      tmp = min(tmp, brute_id);
    }
    occ[num][sz - cnt_used] = brute_id;
    return;
  }
  brute_add(i + 1, num);
  cnt_used++;
  brute_add(i + 1, num * fac[i]);
  cnt_used--;
}
void add(int id) {
  sz = 0;
  int val = a[id], last = lp[val], cnt = 0;
  while (val > 1) {
    if (lp[val] != last) {
      if (cnt) fac[sz++] = last;
      last = lp[val];
      cnt = 0;
    }
    cnt ^= 1;
    val /= lp[val];
  }
  if (cnt) fac[sz++] = last;
  cnt_used = 0;
  brute_id = id;
  brute_add(0, 1);
}
int ans[Q];
vector<pair<int, int>> query[N];
int last[14];
int main() {
  memset(wwww, -1, sizeof wwww);
  memset(ans, -1, sizeof ans);
  memset(occ, -1, sizeof occ);
  memset(vis, 0x3f, sizeof vis);
  memset(last, 0x3f, sizeof last);
  for (int i = 2; i < MAX; i++)
    if (!lp[i])
      for (int j = i; j < MAX; j += i)
        if (!lp[j]) lp[j] = i;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) add(i);
  for (int i = 0, l, r; i < q; i++) {
    scanf("%d %d", &l, &r);
    query[l - 1].emplace_back(r - 1, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 14; j++) {
      last[j] = min(last[j], vis[i][j]);
      assert(last[j] > i);
    }
    for (pair<int, int> x : query[i]) {
      for (int j = 0; j < 14; j++)
        if (last[j] <= x.first) {
          ans[x.second] = j;
          break;
        }
    }
  }
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}
