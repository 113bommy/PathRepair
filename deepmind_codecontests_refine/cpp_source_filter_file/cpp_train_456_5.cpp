#include <bits/stdc++.h>
using namespace std;
const int NMax = 10000, MMax = 1001000;
struct edge {
  int num, a, b;
  edge *next;
} * G[NMax], pool[NMax];
int L;
void Build(int first, int second, int a, int b) {
  edge *p = &pool[L++], *q = &pool[L++];
  p->num = second;
  p->a = a;
  p->b = b;
  p->next = G[first];
  G[first] = p;
  q->num = first;
  q->a = a;
  q->b = b;
  q->next = G[second];
  G[second] = q;
}
int N, M;
int ID[MMax], ID1[MMax], F[NMax];
vector<int> LSH;
void DFS(int a, int first, int second) {
  F[a] = 1;
  for (edge *p = G[a]; p; p = p->next)
    if (!F[p->num] && p->a <= first && p->b >= second)
      DFS(p->num, first, second);
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int a, b, first, second;
    scanf("%d%d%d%d", &a, &b, &first, &second);
    LSH.push_back(first);
    LSH.push_back(second);
    Build(a, b, first, second);
  }
  sort(LSH.begin(), LSH.end());
  int nn = 0;
  for (int i = 0; i < LSH.size(); i++) {
    if (i == 0 || LSH[i] != LSH[i - 1]) {
      ID[LSH[i]] = ++nn;
      ID1[nn] = LSH[i];
    }
  }
  int l = 1, r = 1000005, ret = 0;
  while (l < r) {
    if (l + 1 == r) break;
    int mid = (l + r) >> 1, flag = 0;
    for (int i = 1; i <= nn; i++) {
      memset(F, 0, sizeof(F));
      DFS(1, ID1[i], ID1[i] + mid - 1);
      if (F[N]) {
        l = mid;
        flag = 1;
        ret = 1;
        break;
      }
    }
    if (!flag) r = mid;
  }
  if (!ret)
    puts("Nice work, Dima!");
  else
    printf("%d\n", l);
  return 0;
}
