#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T checkmin(T &a, T b) {
  return (a < b) ? a : a = b;
}
template <class T>
inline T checkmax(T &a, T b) {
  return (a > b) ? a : a = b;
}
template <class T>
T GCD(T a, T b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (a == 0) ? b : GCD(b % a, a);
}
template <class T>
T LCM(T a, T b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return (a == 0 || b == 0) ? 0 : a / GCD(a, b) * b;
}
template <class T>
T sqr(T X) {
  return X * X;
}
namespace Poor {
const int MaxiN = 2005;
int N, Circle, Square;
int A[MaxiN][MaxiN], B[MaxiN][MaxiN], S[MaxiN][MaxiN];
bool Vis[MaxiN][MaxiN];
inline int Ask(int X1, int Y1, int X2, int Y2) {
  return S[X2][Y2] - S[X1 - 1][Y2] - S[X2][Y1 - 1] + S[X1 - 1][Y1 - 1];
}
void Run() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) scanf("%d", &A[i + 1][j + 1]);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
  Circle = Square = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) {
      int X1 = max(i - 3, 1), Y1 = max(j - 3, 1);
      int X2 = min(i + 3, N), Y2 = min(j + 3, N);
      int Sum = Ask(X1, Y1, X2, Y2);
      int Tot = (X2 - X1 + 1) * (Y2 - Y1 + 1);
      double Rate = (double)Sum / (double)Tot;
      B[i][j] = (Rate > 0.37);
    }
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (B[i][j] && !Vis[i][j]) {
        deque<pair<int, int> > Q;
        Q.push_back(make_pair(i, j));
        vector<pair<int, int> > Visitor;
        Vis[i][j] = 1;
        while (!Q.empty()) {
          int CX = Q.front().first, CY = Q.front().second;
          Q.pop_front();
          Visitor.push_back(make_pair(CX, CY));
          for (int a = -1; a <= 1; ++a)
            for (int b = -1; b <= 1; ++b) {
              int TX = CX + a, TY = CY + b;
              if (TX >= 1 && TX <= N && TY >= 1 && TY <= N && !Vis[TX][TY] &&
                  B[TX][TY]) {
                Vis[TX][TY] = 1;
                Q.push_back(make_pair(TX, TY));
              }
            }
        }
        int MinX = INT_MAX, MaxX = INT_MIN;
        int MinY = INT_MAX, MaxY = INT_MIN;
        for (typeof(Visitor.begin()) it = Visitor.begin(); it != Visitor.end();
             ++it) {
          checkmin(MinX, it->first);
          checkmax(MaxX, it->first);
          checkmin(MinY, it->second);
          checkmax(MaxY, it->second);
        }
        if (MaxY - MinY <= 9 || MaxX - MinX <= 9) continue;
        double X = 0, Y = 0;
        for (typeof(Visitor.begin()) it = Visitor.begin(); it != Visitor.end();
             ++it)
          X += it->first, Y += it->second;
        X /= Visitor.size(), Y /= Visitor.size();
        double R = min(min(fabs(X - MinX), fabs(MaxX - X)),
                       min(fabs(Y - MinY), fabs(MaxY - Y)));
        int Count = 0;
        for (typeof(Visitor.begin()) it = Visitor.begin(); it != Visitor.end();
             ++it)
          if (sqr(X - it->first) + sqr(Y - it->second) <= sqr(R)) ++Count;
        double Rate =
            (double)Count / (double)((MaxX - MinX + 1) * (MaxY - MinY + 1));
        double Rate2 = (double)Visitor.size() /
                       (double)((MaxX - MinX + 1) * (MaxY - MinY + 1));
        if ((Count + 20 >= (int)Visitor.size() ||
             (double)Count / (double)Visitor.size() > 0.92) &&
            fabs(Rate - 3.1415926 / 4.0) < 0.1 &&
            fabs(Rate2 - 3.1415926 / 4.0) < 0.1)
          ++Circle;
        else
          ++Square;
      }
  cout << Circle << " " << Square << endl;
}
}  // namespace Poor
int main() {
  Poor::Run();
  return 0;
}
