#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const int MAXN = 1e5 + 11;
int N, A[7], B[7][MAXN];
multiset<int> s;
void Ins(int w) {
  s.insert(w);
  return;
}
void Del(int w) {
  s.erase(s.find(w));
  return;
}
int Qmax() { return *(--s.end()); }
struct Node {
  int w;
  pair<int, int> p;
} tmp[MAXN * 7];
bool cmp(Node x1, Node x2) { return x1.w < x2.w; }
int Ps[MAXN], Ans = INT_MAX, tot;
int main() {
  for (int i = 1; i <= 6; i++) A[i] = read();
  sort(A + 1, A + 7);
  N = read();
  for (int i = 1; i <= N; i++) {
    int x = read();
    for (int j = 1; j <= 6; j++) B[j][i] = x - A[j];
  }
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j <= N; j++) {
      ++tot;
      tmp[tot].w = B[i][j], tmp[tot].p = make_pair(i, j);
    }
  sort(tmp + 1, tmp + tot + 1, cmp);
  int ps = 1;
  for (int i = 1; i <= N; i++) Ins(B[6][i]), Ps[i] = 6;
  bool ff = 1;
  if (N == 1) {
    printf("%d\n", 0);
    return 0;
  }
  while (ps <= tot) {
    int l = ps, r;
    for (r = ps; tmp[r].w == tmp[l].w; r++)
      ;
    r--;
    for (int i = l; i <= r; i++) {
      Del(tmp[i].w), Ans = min(Ans, Qmax() - tmp[l].w), Ins(tmp[i].w);
    }
    for (int i = l; i <= r; i++) {
      Del(tmp[i].w), Ps[tmp[i].p.second]--;
      if (!Ps[tmp[i].p.second]) ff = 0;
      Ins(B[Ps[tmp[i].p.second]][tmp[i].p.second]);
    }
    if (!ff) break;
    ps = r + 1;
  }
  printf("%d\n", Ans);
  return 0;
}
