#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, INF1 = 0x7FFFFFFF;
const long long INF2 = 0x7FFFFFFFFFFFFFFF;
struct node {
  int pos, No, fix;
  long long tim;
  node *L, *R;
} * root, tree[maxn << 1];
struct datas {
  int pos, No;
  long long tim;
  friend bool operator<(datas A, datas B) { return A.tim > B.tim; }
  datas() {}
  datas(int A, long long B, int C) : pos(A), tim(B), No(C) {}
};
priority_queue<datas> Q;
int n, car, peo, cur = -1;
void Lrot(node *&A) {
  node *B = A->R;
  A->R = B->L;
  B->L = A;
  A = B;
}
void Rrot(node *&A) {
  node *B = A->L;
  A->L = B->R;
  B->R = A;
  A = B;
}
void Insert(node *&P, int A, long long B, int C) {
  if (!P) {
    cur++;
    P = tree + cur;
    P->pos = A;
    P->tim = B;
    P->No = C;
    P->fix = rand();
    return;
  }
  if (A < P->pos || A == P->pos && B < P->tim ||
      A == P->pos && B == P->tim && C < P->No) {
    Insert(P->L, A, B, C);
    if (P->L->fix < P->fix) Rrot(P);
  } else {
    Insert(P->R, A, B, C);
    if (P->R->fix < P->fix) Lrot(P);
  }
}
node *prev(node *P, int A, long long B, int C) {
  if (!P) return NULL;
  if (A < P->pos || A == P->pos && B < P->tim ||
      A == P->pos && B == P->tim && C < P->No)
    return prev(P->L, A, B, C);
  else {
    node *res = prev(P->R, A, B, C);
    return res ? res : P;
  }
}
node *succ(node *P, int A, long long B, int C) {
  if (!P) return NULL;
  if (A < P->pos || A == P->pos && B < P->tim ||
      A == P->pos && B == P->tim && C < P->No) {
    node *res = succ(P->L, A, B, C);
    return res ? res : P;
  } else
    return succ(P->R, A, B, C);
}
void Delete(node *&P, node *Q) {
  if (P == Q) {
    if (P->L && P->R) {
      if (P->L->fix < P->R->fix)
        Rrot(P), Delete(P->R, Q);
      else
        Lrot(P), Delete(P->L, Q);
    } else
      P = P->L ? P->L : P->R;
    return;
  }
  if (Q->pos < P->pos || Q->pos == P->pos && Q->tim < P->tim ||
      Q->pos == P->pos && Q->tim == P->tim && Q->No < P->No)
    Delete(P->L, Q);
  else
    Delete(P->R, Q);
}
int main() {
  scanf("%d%d%d", &n, &car, &peo);
  for (int i = 1, x; i <= car; i++) {
    scanf("%d", &x);
    Insert(root, x, 0, i);
  }
  long long T = 0;
  for (int i = 1, a, b; i <= peo; i++) {
    long long t, L = INF2, R = INF2;
    scanf("%lld%d%d", &t, &a, &b);
    T = max(T, t);
    if (!root) T = max(T, Q.top().tim);
    while (!Q.empty() && Q.top().tim <= T) {
      Insert(root, Q.top().pos, Q.top().tim, Q.top().No);
      Q.pop();
    }
    node *u = prev(root, a, INF2, INF1), *v = succ(root, a, 0, 0);
    if (u) u = succ(root, u->pos - 1, INF2, INF1);
    if (u) L = a - u->pos + (t < u->tim ? u->tim - t : 0);
    if (v) R = v->pos - a + (t < v->tim ? v->tim - t : 0);
    if (L < R || L == R && u->tim < v->tim ||
        L == R && u->tim == v->tim && u->No < v->No)
      printf("%d %lld\n", u->No, L),
          Q.push(datas(b, T + L + abs(a - b), u->No)), Delete(root, u);
    else
      printf("%d %lld\n", v->No, R),
          Q.push(datas(b, T + R + abs(a - b), v->No)), Delete(root, v);
  }
  return 0;
}
