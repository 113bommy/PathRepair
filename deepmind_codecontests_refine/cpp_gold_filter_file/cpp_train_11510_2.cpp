#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1000005], c[1000005], ans[1000005];
int allxorS[1000005];
int lowbit(int x);
void update(int x, int dv);
int getsum(int x);
void printC();
struct Req {
  int l, r;
  int id;
  Req(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
  bool operator<(const Req& q1) const { return r < q1.r; }
};
vector<Req> Adj[1000005];
map<int, int> lastPos;
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
    allxorS[i] = allxorS[i - 1] ^ a[i];
  }
  int l, r, id, x;
  cin >> M;
  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &l, &r);
    Adj[r].push_back(Req(l, r, i));
  }
  for (int i = 1; i <= N; i++) {
    x = a[i];
    if (lastPos.count(x) != 0) update(lastPos[x], x);
    lastPos[x] = i;
    update(i, x);
    for (int j = 0; j < Adj[i].size(); j++) {
      id = Adj[i][j].id;
      l = Adj[i][j].l;
      r = i;
      ans[id] = allxorS[r] ^ allxorS[l - 1] ^ getsum(r) ^ getsum(l - 1);
    }
  }
  for (int i = 1; i <= M; i++) printf("%d\n", ans[i]);
  return 0;
}
int lowbit(int x) { return x & (-x); }
void update(int x, int dv) {
  if (x == 0) return;
  for (; x <= N; x += lowbit(x)) c[x] ^= dv;
}
int getsum(int x) {
  int ans = 0;
  for (; x; x -= lowbit(x)) ans ^= c[x];
  return ans;
}
