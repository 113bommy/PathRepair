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
namespace Segment_Tree {
class Data {
 public:
  int Left, Right;
  long long Sum;
  inline bool operator<(Data const &a) const { return Sum < a.Sum; }
  inline Data operator+(Data const &a) const {
    return (Data){Left, a.Right, Sum + a.Sum};
  }
};
class Node {
 public:
  Data LeftMax, RightMax, Max, LeftMin, RightMin, Min, Sum;
  inline Node operator+(Node const &a) const {
    Node x;
    x.LeftMax = max(LeftMax, Sum + a.LeftMax);
    x.RightMax = max(a.RightMax, RightMax + a.Sum);
    x.Max = max(x.LeftMax, x.RightMax);
    x.Max = max(x.Max, Max);
    x.Max = max(x.Max, a.Max);
    x.Max = max(x.Max, RightMax + a.LeftMax);
    x.LeftMin = min(LeftMin, Sum + a.LeftMin);
    x.RightMin = min(a.RightMin, RightMin + a.Sum);
    x.Min = min(x.LeftMin, x.RightMin);
    x.Min = min(x.Min, Min);
    x.Min = min(x.Min, a.Min);
    x.Min = min(x.Min, RightMin + a.LeftMin);
    x.Sum = Sum + a.Sum;
    return x;
  }
} A[200005 * 4];
bool Reverse[200005 * 4];
inline void Push_Down(int Now) {
  if (Reverse[Now]) {
    swap(A[Now].LeftMax, A[Now].LeftMin);
    swap(A[Now].RightMax, A[Now].RightMin);
    swap(A[Now].Min, A[Now].Max);
    A[Now].LeftMax.Sum *= -1;
    A[Now].RightMax.Sum *= -1;
    A[Now].Max.Sum *= -1;
    A[Now].LeftMin.Sum *= -1;
    A[Now].RightMin.Sum *= -1;
    A[Now].Min.Sum *= -1;
    A[Now].Sum.Sum *= -1;
    Reverse[Now << 1] ^= 1;
    Reverse[Now << 1 | 1] ^= 1;
    Reverse[Now] = false;
  }
}
inline void Update(int Now) {
  Push_Down(Now << 1);
  Push_Down(Now << 1 | 1);
  A[Now] = A[Now << 1] + A[Now << 1 | 1];
}
void Build(int Now, int *Value, int Left, int Right) {
  if (Left == Right) {
    A[Now].LeftMin = A[Now].RightMin = A[Now].Min = A[Now].LeftMax =
        A[Now].RightMax = A[Now].Max = A[Now].Sum =
            (Data){Left, Left, Value[Left]};
    return;
  }
  int Mid = Left + Right >> 1;
  Build(Now << 1, Value, (0 ? Mid + 1 : Left), (0 ? Right : Mid));
  Build(Now << 1 | 1, Value, (1 ? Mid + 1 : Left), (1 ? Right : Mid));
  Update(Now);
}
void Modify(int Now, int Position, int Value, int Left, int Right) {
  Push_Down(Now);
  if (Left == Right) {
    A[Now].LeftMin = A[Now].RightMin = A[Now].Min = A[Now].LeftMax =
        A[Now].RightMax = A[Now].Max = A[Now].Sum = (Data){Left, Left, Value};
    return;
  }
  int Mid = Left + Right >> 1, i = Position > Mid;
  Modify(Now << 1 | i, Position, Value, (i ? Mid + 1 : Left),
         (i ? Right : Mid));
  Update(Now);
}
void Flip(int Now, int left, int right, int Left, int Right) {
  Push_Down(Now);
  if (left == Left && right == Right) {
    Reverse[Now] ^= 1;
    return;
  }
  int Mid = Left + Right >> 1;
  if (left > Mid || right <= Mid) {
    int i = left > Mid;
    Flip(Now << 1 | i, left, right, (i ? Mid + 1 : Left), (i ? Right : Mid));
  } else {
    Flip(Now << 1, left, Mid, (0 ? Mid + 1 : Left), (0 ? Right : Mid));
    Flip(Now << 1 | 1, Mid + 1, right, (1 ? Mid + 1 : Left), (1 ? Right : Mid));
  }
  Update(Now);
}
Node Query(int Now, int left, int right, int Left, int Right) {
  Push_Down(Now);
  if (left == Left && right == Right) return A[Now];
  int Mid = Left + Right >> 1;
  if (left > Mid || right <= Mid) {
    int i = left > Mid;
    return Query(Now << 1 | i, left, right, (i ? Mid + 1 : Left),
                 (i ? Right : Mid));
  }
  return Query(Now << 1, left, Mid, (0 ? Mid + 1 : Left), (0 ? Right : Mid)) +
         Query(Now << 1 | 1, Mid + 1, right, (1 ? Mid + 1 : Left),
               (1 ? Right : Mid));
}
}  // namespace Segment_Tree
int N, Q, Top;
int Value[200005], temp1[200005], temp2[200005];
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) Value[i] = Get_Int();
  Segment_Tree::Build(1, Value, 1, N);
  cin >> Q;
  while (Q--)
    if (Get_Int()) {
      int Left = Get_Int(), Right = Get_Int(), K = Get_Int();
      long long Ans = 0;
      while (K--) {
        Segment_Tree::Node Now = Segment_Tree::Query(1, Left, Right, 1, N);
        if (Now.Max.Sum <= 0) break;
        Ans += Now.Max.Sum;
        temp1[++Top] = Now.Max.Left;
        temp2[Top] = Now.Max.Right;
        Segment_Tree::Flip(1, Now.Max.Left, Now.Max.Right, 1, N);
      }
      while (Top) {
        Segment_Tree::Flip(1, temp1[Top], temp2[Top], 1, N);
        --Top;
      }
      printf("%lld\n", max(Ans, 0LL));
    } else {
      int x = Get_Int(), y = Get_Int();
      Segment_Tree::Modify(1, x, y, 1, N);
    }
  return 0;
}
