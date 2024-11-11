#include <bits/stdc++.h>
using namespace std;
struct AnsType {
  int Len;
  long long Hash0, Hash1;
};
struct Node {
  int Left, Right, Mid;
  AnsType Data;
  Node *Lc, *Rc;
};
long long Pow[400001];
AnsType operator+(AnsType A, AnsType B) {
  AnsType Ans;
  Ans.Len = A.Len + B.Len;
  Ans.Hash0 = A.Hash0 * Pow[B.Len] + B.Hash0;
  Ans.Hash1 = B.Hash1 * Pow[A.Len] + A.Hash1;
  return Ans;
}
const int Seed = 19961021;
int Len, N = 0;
bool Find = false;
char Start[400000], Ans[400000];
Node *Root;
Node *Build(int L, int R) {
  Node *P = new Node;
  P->Left = L;
  P->Right = R;
  P->Mid = (L + R) / 2;
  P->Data.Len = R - L + 1;
  if (L < R) {
    P->Lc = Build(L, P->Mid);
    P->Rc = Build(P->Mid + 1, R);
  }
  return P;
}
void Modify(Node *P, int X, int T) {
  if (P->Left == P->Right) {
    P->Data.Hash0 = P->Data.Hash1 = T;
    return;
  }
  Modify((X <= P->Mid) ? P->Lc : P->Rc, X, T);
  P->Data = P->Lc->Data + P->Rc->Data;
}
AnsType Get(Node *P, int L, int R) {
  if (P->Left == L && P->Right == R) return P->Data;
  if (R <= P->Mid) return Get(P->Lc, L, R);
  if (L > P->Mid) return Get(P->Rc, L, R);
  return Get(P->Lc, L, P->Mid) + Get(P->Rc, P->Mid + 1, R);
}
void DFS(int Depth, bool Flag) {
  if (Depth == N) {
    Find = Flag;
    return;
  }
  for (char c = Flag ? 'a' : Start[Depth]; !Find && c <= 'z'; c++) {
    Modify(Root, Depth, c);
    Ans[Depth] = c;
    if (Depth >= Len - 1) {
      AnsType T = Get(Root, Depth - Len + 1, Depth);
      if (T.Hash0 == T.Hash1) continue;
    }
    if (Depth >= Len) {
      AnsType T = Get(Root, Depth - Len, Depth);
      if (T.Hash0 == T.Hash1) continue;
    }
    DFS(Depth + 1, Flag || (c > Start[Depth]));
  }
}
int main() {
  scanf("%d", &Len);
  char c;
  while (c = getchar(), c < 'a' || c > 'z')
    ;
  while (c >= 'a' && c <= 'z') {
    Start[N++] = c;
    c = getchar();
  }
  Pow[0] = 1;
  for (int i = 0; i < N; i++) Pow[i + 1] = Pow[i] * Seed;
  Root = Build(0, N - 1);
  DFS(0, 0);
  if (!Find)
    printf("Impossible\n");
  else {
    for (int i = 0; i < N; i++) putchar(Ans[i]);
    putchar('\n');
  }
  return 0;
}
