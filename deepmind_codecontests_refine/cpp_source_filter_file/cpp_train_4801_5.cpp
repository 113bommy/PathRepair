#include <bits/stdc++.h>
using namespace std;
struct Data {
  int X, Y, V;
};
bool operator<(Data A, Data B) { return A.V < B.V; }
struct Painter {
  int X, Y, Type;
};
struct HashType {
  int X, Y;
  HashType *Next;
};
int Get() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && (c != '-'))
    ;
  bool Flag = (c == '-');
  if (Flag) c = getchar();
  int X = c - 48;
  while (c = getchar(), c >= '0' && c <= '9') X = X * 10 + c - 48;
  return Flag ? -X : X;
}
const int BigNumber = 99991;
int Ox, Oy;
int Parent[90000];
HashType *Hash[BigNumber];
bool operator<(Painter A, Painter B) {
  int L0 = max(abs(A.X - Ox), abs(A.Y - Oy));
  int L1 = max(abs(B.X - Ox), abs(B.Y - Oy));
  if (L0 < L1) return true;
  if (L0 > L1) return false;
  int T0, X0, T1, X1;
  if (A.Y == Oy - L0) {
    T0 = 3;
    X0 = -A.X;
  } else if (A.X == Ox + L0) {
    T0 = 2;
    X0 = -A.Y;
  } else if (A.Y == Oy + L0) {
    T0 = 1;
    X0 = A.X;
  } else if (A.X == Ox - L0) {
    T0 = 0;
    X0 = A.Y;
  }
  if (B.Y == Oy - L1) {
    T0 = 3;
    X0 = -B.X;
  } else if (B.X == Ox + L1) {
    T0 = 2;
    X0 = -B.Y;
  } else if (B.Y == Oy + L1) {
    T0 = 1;
    X0 = B.X;
  } else if (B.X == Ox - L1) {
    T0 = 0;
    X0 = B.Y;
  }
  return (T0 == T1) ? (X0 < X1) : (T0 < T1);
}
int Root(int X) { return (Parent[X] == X) ? X : (Parent[X] = Root(Parent[X])); }
int Find(int X) {
  HashType *P = Hash[X % BigNumber];
  while (P != NULL)
    if (P->X == X)
      return P->Y;
    else
      P = P->Next;
  return -1;
}
void Add(int X, int Y) {
  int V = X % BigNumber;
  HashType *P = new HashType;
  P->X = X;
  P->Y = Y;
  P->Next = Hash[V];
  Hash[V] = P;
}
void Delete(int X) {
  int V = X % BigNumber;
  HashType *P = Hash[V], *Pre = NULL;
  while (P->X != X) {
    Pre = P;
    P = P->Next;
  }
  if (Pre == NULL)
    Hash[V] = Hash[V]->Next;
  else
    Pre->Next = P->Next;
  delete P;
}
int main() {
  int M = Get(), N = Get();
  static Data A[90000];
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) A[i * N + j] = (Data){i, j, Get()};
  sort(A, A + M * N);
  int Total = 0;
  static int Group[300][300], Size[90000], Color[90000];
  memset(Size, 0, sizeof(Size));
  for (int i = 0; i < M * N; i++) {
    Group[A[i].X][A[i].Y] = Total;
    Size[Total]++;
    Color[Total] = A[i].V;
    if (i + 1 == M * N || A[i].V != A[i + 1].V) Total++;
  }
  for (int i = 0; i < Total; i++) Parent[i] = i;
  for (int i = 0; i < Total; i++) Add(Color[i], i);
  vector<Painter> List[90000];
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      int T = Get();
      if (T == -1) continue;
      List[Group[i][j]].push_back((Painter){i, j, T});
    }
  static int Qx[90000], Qy[90000], Qt[90000];
  int F = 0, R = 1;
  Qx[0] = Get() - 1;
  Qy[0] = Get() - 1;
  int Temp = Group[Qx[0]][Qy[0]];
  for (int i = 0; i < List[Temp].size(); i++)
    if (List[Temp][i].X == Qx[0] && List[Temp][i].Y == Qy[0])
      Qt[0] = List[Temp][i].Type;
  static bool Paint[90000];
  memset(Paint, 0, sizeof(Paint));
  long long Ans = 0;
  while (F < R) {
    int X = Qx[F], Y = Qy[F], T = Qt[F];
    F++;
    int W = Root(Group[X][Y]);
    if (!Color[W] || Color[W] == T) continue;
    Ans += Size[W];
    int H = Find(T);
    Delete(Color[W]);
    if (H == -1)
      Add(Color[W] = T, W);
    else {
      Parent[W] = H;
      Size[H] += Size[W];
    }
    if (Paint[W]) continue;
    Paint[W] = true;
    Ox = X;
    Oy = Y;
    sort(List[W].begin(), List[W].end());
    for (int i = 0; i < List[W].size(); i++) {
      Qx[R] = List[W][i].X;
      Qy[R] = List[W][i].Y;
      Qt[R] = List[W][i].Type;
      if (Qx[R] == Qx[0] && Qy[R] == Qy[0]) continue;
      R++;
    }
  }
  cout << Ans << endl;
  return 0;
}
