#include <bits/stdc++.h>
using namespace std;
const int SIZEN = 10010;
class NODE {
 public:
  int f;
  int k;
};
NODE ufs[SIZEN];
vector<pair<int, NODE> > OPS;
NODE grand(int x, bool flag) {
  if (ufs[x].f == x) return ufs[x];
  NODE ans = grand(ufs[x].f, flag);
  ans.k ^= ufs[x].k;
  if (flag) OPS.push_back(make_pair(x, ufs[x]));
  return ufs[x] = ans;
}
bool merge(int a, int b, bool flag) {
  NODE ga = grand(a, flag), gb = grand(b, flag);
  if (ga.f == gb.f) return ga.k ^ gb.k;
  gb.k = (ga.k ^ gb.k ^ 1);
  if (flag) OPS.push_back(make_pair(ga.f, ufs[ga.f]));
  ufs[ga.f] = gb;
  return true;
}
int N, M;
int SZ, K;
int u[SIZEN] = {0}, v[SIZEN] = {0};
int head[SIZEN] = {0}, tail[SIZEN] = {0};
vector<int> ans;
void clear_ufs(void) {
  for (int i = 1; i <= M; i++) ufs[i].f = i, ufs[i].k = 0;
}
void test_block(int k) {
  clear_ufs();
  for (int i = 1; i < head[k]; i++)
    if (!merge(u[i], v[i], 0)) return;
  for (int i = tail[k] + 1; i <= M; i++)
    if (!merge(u[i], v[i], 0)) return;
  OPS.clear();
  for (int i = head[k]; i <= tail[k]; i++) {
    bool flag = true;
    for (int j = head[k]; j <= tail[k]; j++) {
      if (j == i) continue;
      if (!merge(u[j], v[j], 1)) {
        flag = false;
        break;
      }
    }
    if (flag) ans.push_back(i);
    for (int j = OPS.size() - 1; j >= 0; j--) ufs[OPS[j].first] = OPS[j].second;
    OPS.clear();
  }
}
void work(void) {
  for (int i = 1; i <= K; i++) test_block(i);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  printf("\n");
}
void read(void) {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) scanf("%d%d", &u[i], &v[i]);
  SZ = sqrt(M + 0.5);
  int tot = 0;
  K = 1;
  head[1] = 1;
  for (int i = 1; i <= M; i++) {
    tot++;
    if (i == M || tot == SZ) {
      tot = 0;
      tail[K] = i;
      head[++K] = i + 1;
    }
  }
  K--;
}
int main() {
  read();
  work();
  return 0;
}
