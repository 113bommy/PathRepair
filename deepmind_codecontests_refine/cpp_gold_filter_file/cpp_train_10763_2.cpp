#include <bits/stdc++.h>
using namespace std;
inline int Get_Int() {
  int Num = 0, Flag = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') Flag = -Flag;
  } while (ch < '0' || ch > '9');
  do {
    Num = Num * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return Num * Flag;
}
class Matrix {
 public:
  int N, M;
  long long A[2][2];
  inline Matrix operator*(Matrix const &a) const {
    Matrix Ans;
    memset(&Ans, 0, sizeof(Ans));
    Ans.N = N;
    Ans.M = a.M;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < a.M; ++j)
        for (int k = 0; k < M; ++k)
          Ans.A[i][j] = (Ans.A[i][j] + A[i][k] * a.A[k][j]) % 1000000000;
    return Ans;
  }
  inline Matrix operator+(Matrix const &a) const {
    Matrix Ans;
    Ans.N = N;
    Ans.M = M;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        Ans.A[i][j] = (A[i][j] + a.A[i][j]) % 1000000000;
    return Ans;
  }
} M[200005], Transform;
int N, Q;
long long A[200005], F[200005];
namespace Segment_Tree {
long long Tag[200005 * 4], Size[200005 * 4];
Matrix Sum[200005 * 4];
inline void Push_Down(int x) {
  if (Tag[x]) {
    Sum[x].A[0][0] = (Sum[x].A[0][0] + F[Size[x] - 1] * Tag[x]) % 1000000000;
    Sum[x].A[0][1] = (Sum[x].A[0][1] + F[Size[x]] * Tag[x]) % 1000000000;
    if (Size[x] > 1)
      for (int i = 0; i < 2; ++i)
        Tag[x << 1 | i] = (Tag[x << 1 | i] + Tag[x]) % 1000000000;
    Tag[x] = 0;
  }
}
inline void Update(int x) {
  Push_Down(x << 1);
  Push_Down(x << 1 | 1);
  Sum[x] = Sum[x << 1] + (Sum[x << 1 | 1] * M[Size[x << 1]]);
}
void Build(int x, int Left, int Right) {
  Size[x] = Right - Left + 1;
  Sum[x].N = 1;
  Sum[x].M = 2;
  if (Left == Right) {
    Sum[x].A[0][1] = A[Left];
    return;
  }
  int Mid = Left + Right >> 1;
  Build(x << 1, (0 ? Mid + 1 : Left), (0 ? Right : Mid));
  Build(x << 1 | 1, (1 ? Mid + 1 : Left), (1 ? Right : Mid));
  Update(x);
}
void Increase(int x, int left, int right, int Value, int Left, int Right) {
  Push_Down(x);
  if (left == Left && right == Right) {
    Tag[x] = Value;
    Push_Down(x);
    return;
  }
  int Mid = Left + Right >> 1;
  if (left > Mid || right <= Mid) {
    int i = left > Mid;
    Increase(x << 1 | i, left, right, Value, (i ? Mid + 1 : Left),
             (i ? Right : Mid));
  } else {
    Increase(x << 1, left, Mid, Value, (0 ? Mid + 1 : Left), (0 ? Right : Mid));
    Increase(x << 1 | 1, Mid + 1, right, Value, (1 ? Mid + 1 : Left),
             (1 ? Right : Mid));
  }
  Update(x);
}
void Change(int x, int Position, int Value, int Left, int Right) {
  Push_Down(x);
  if (Left == Right) {
    Sum[x].A[0][1] = Value;
    return;
  }
  int Mid = Left + Right >> 1, i = Position > Mid;
  Change(x << 1 | i, Position, Value, (i ? Mid + 1 : Left), (i ? Right : Mid));
  Update(x);
}
Matrix Query(int x, int left, int right, int Left, int Right) {
  Push_Down(x);
  if (left == Left && right == Right) return Sum[x];
  int Mid = Left + Right >> 1;
  if (left > Mid || right <= Mid) {
    int i = left > Mid;
    return Query(x << 1 | i, left, right, (i ? Mid + 1 : Left),
                 (i ? Right : Mid));
  }
  return Query(x << 1, left, Mid, (0 ? Mid + 1 : Left), (0 ? Right : Mid)) +
         (Query(x << 1 | 1, Mid + 1, right, (1 ? Mid + 1 : Left),
                (1 ? Right : Mid)) *
          M[Mid - left + 1]);
}
}  // namespace Segment_Tree
int main() {
  cin >> N >> Q;
  F[1] = 1;
  for (int i = 2; i <= N; ++i) F[i] = (F[i - 1] + F[i - 2]) % 1000000000;
  for (int i = 2; i <= N; ++i) F[i] = (F[i] + F[i - 1]) % 1000000000;
  Transform.N = Transform.M = M[0].N = M[0].M = 2;
  M[0].A[0][0] = M[0].A[1][1] = 1;
  Transform.A[0][1] = Transform.A[1][0] = Transform.A[1][1] = 1;
  for (int i = 1; i <= N; ++i) M[i] = M[i - 1] * Transform;
  for (int i = 1; i <= N; ++i) A[i] = Get_Int();
  Segment_Tree::Build(1, 1, N);
  while (Q--) {
    int Op = Get_Int(), x = Get_Int(), y = Get_Int();
    if (Op == 1)
      Segment_Tree::Change(1, x, y, 1, N);
    else if (Op == 2)
      printf("%lld\n", Segment_Tree::Query(1, x, y, 1, N).A[0][1]);
    else
      Segment_Tree::Increase(1, x, y, Get_Int(), 1, N);
  }
  return 0;
}
