#include <bits/stdc++.h>
inline int Abs(int K) { return K > 0 ? K : -K; }
struct ele_t {
  int pA, pB, val;
  bool operator<(const ele_t &cmp) const {
    if (val != cmp.val)
      return val > cmp.val;
    else
      return pA > cmp.pA;
  }
  ele_t() {}
  ele_t(int a, int b, int c) { pA = a, pB = b, val = c; }
};
struct man {
  int gen, nxt, pre, val;
} M[200001];
int N;
int ans[200001][2], ac;
char line[200001];
bool use[200001];
std::priority_queue<ele_t> Q;
int fst, lst;
void del(int pos) {
  use[pos] = true;
  if (pos == fst) {
    fst = M[pos].nxt;
    M[M[pos].nxt].pre = -1;
  } else if (pos == lst) {
    lst = M[pos].pre;
    M[M[pos].pre].nxt = -1;
  } else {
    int a = M[M[pos].pre].nxt = M[pos].nxt;
    int b = M[M[pos].nxt].pre = M[pos].pre;
    if (M[a].gen != M[b].gen) Q.push(ele_t(b, a, Abs(M[b].val - M[a].val)));
  }
  return;
}
int main() {
  scanf("%d", &N);
  fst = 0, lst = N - 1;
  scanf("%s", line);
  for (int i = 0; i < N; i++) scanf("%d", &M[i].val);
  for (int i = 0; i < N - 1; i++) M[i].nxt = i + 1;
  for (int i = 1; i < N; i++) M[i].pre = i - 1;
  M[0].pre = -1;
  M[N - 1].nxt = -1;
  for (int i = 0; i < N; i++) M[i].gen = line[i] == 'B' ? 1 : 0;
  for (int i = 0; i < N - 1; i++)
    if (M[i].gen != M[i + 1].gen)
      Q.push(ele_t(i, i + 1, Abs(M[i].val - M[i + 1].val)));
  while (!Q.empty()) {
    ele_t now = Q.top();
    Q.pop();
    if (use[now.pA] || use[now.pB]) continue;
    del(now.pA);
    del(now.pB);
    ans[ac][0] = now.pA;
    ans[ac][1] = now.pB;
    ++ac;
  }
  printf("%d\n", ac);
  for (int i = 0; i < ac; i++) printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
}
