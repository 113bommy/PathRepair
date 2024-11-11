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
class Request {
 public:
  int Left, Right, K, ID;
  inline bool operator<(Request const &a) const {
    if (K == a.K)
      return Right < a.Right;
    else
      return K < a.K;
  }
} Query[100005];
int N, Q, Total, Size;
int A[100005], Ans[100005];
class Data {
 public:
  int Num, Sum;
  int D[100005];
  vector<int> Position[100005];
  inline void Insert(int i) {
    if (Position[A[i]].empty())
      ++Num, ++Sum;
    else if (D[A[i]] != -1) {
      vector<int>::iterator it = --Position[A[i]].end();
      if (D[A[i]] == 0) D[A[i]] = abs(*it - i);
      if (abs(*it - i) != D[A[i]]) {
        --Num;
        D[A[i]] = -1;
      }
    }
    Position[A[i]].push_back(i);
  }
  inline void Clear(int i) {
    D[i] = 0;
    Position[i].clear();
  }
} A1, A2;
int main() {
  cin >> N;
  Size = sqrt(N);
  for (int i = 1; i <= N; ++i) A[i] = Get_Int();
  cin >> Q;
  for (int i = 1; i <= Q; ++i) {
    int Left = Get_Int(), Right = Get_Int();
    if (Right - Left + 1 <= Size) {
      for (int j = Left; j <= Right; ++j) A1.Insert(j);
      Ans[i] = A1.Sum + (A1.Num == 0);
      for (int j = Left; j <= Right; ++j) A1.Clear(A[j]);
      A1.Num = A1.Sum = 0;
    } else {
      Query[++Total].Left = Left;
      Query[Total].Right = Right;
      Query[Total].K = (Query[Total].Left - 1) / Size + 1;
      Query[Total].ID = i;
    }
  }
  sort(Query + 1, Query + Total + 1);
  int Last = 0;
  for (int i = 1; i <= Total; ++i) {
    if (Query[i].K != Query[i - 1].K) {
      for (int j = 1; j <= 100000; ++j) A1.Clear(j);
      A1.Num = A1.Sum = 0;
      Last = Query[i].K * Size;
    }
    for (int j = Last + 1; j <= Query[i].Right; ++j) A1.Insert(j);
    for (int j = Query[i].Left; j <= Query[i].K * Size; ++j) A2.Insert(j);
    int Sum = A1.Sum, Num = A1.Num;
    for (int j = Query[i].Left; j <= Query[i].K * Size; ++j)
      if (A2.Position[A[j]].size()) {
        if (A1.Position[A[j]].size()) {
          int temp = *A1.Position[A[j]].begin() - *--A2.Position[A[j]].end();
          Num -= (A1.D[A[j]] != -1 &&
                  (temp != (A1.D[A[j]] == 0 ? temp : A1.D[A[j]]) ||
                   temp != (A2.D[A[j]] == 0 ? temp : A1.D[A[j]])));
        } else
          ++Sum, Num += (A2.D[A[j]] != -1);
        A2.Clear(A[j]);
      }
    A2.Num = A2.Sum = 0;
    Ans[Query[i].ID] = Sum + (Num == 0);
    Last = Query[i].Right;
  }
  for (int i = 1; i <= Q; ++i) printf("%d\n", Ans[i]);
  return 0;
}
