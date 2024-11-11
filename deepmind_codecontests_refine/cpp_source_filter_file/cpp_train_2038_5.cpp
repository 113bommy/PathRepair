#include <bits/stdc++.h>
using namespace std;
struct Point {
  double X, Y;
  void Get() { cin >> X >> Y; }
};
struct Data {
  Point O;
  int Num;
  bool Change;
};
bool operator<(Data A, Data B) {
  return (A.O.X == B.O.X) ? (A.O.Y < B.O.Y) : (A.O.X < B.O.X);
}
struct Edge {
  int Data;
  double Weight;
};
struct Node {
  int Number;
  double Dist;
};
bool operator<(Node A, Node B) { return A.Dist > B.Dist; }
const double inf = 1e9;
const double eps = 1e-6;
Point Cross(Point A, Point B, Point C, Point D) {
  double A0 = A.Y - B.Y, B0 = B.X - A.X, C0 = A.X * B.Y - A.Y * B.X;
  double A1 = C.Y - D.Y, B1 = D.X - C.X, C1 = C.X * D.Y - C.Y * D.X;
  if (A0 * B1 == B0 * C1) return (Point){inf, inf};
  Point O;
  O.X = (C1 * B0 - C0 * B1) / (A0 * B1 - A1 * B0);
  O.Y = (C1 * A0 - C0 * A1) / (B0 * A1 - B1 * A0);
  return O;
}
double F(Point A, Point B, Point C) {
  return (A.X * B.Y + B.X * C.Y + C.X * A.Y) -
         (A.Y * B.X + B.Y * C.X + C.Y * A.X);
}
bool On(Point A, Point B, Point C) {
  if (fabs(F(A, B, C)) > eps) return false;
  if (fabs(A.X - B.X) < eps && fabs(A.Y - B.Y) < eps) return false;
  if (fabs(B.X - C.X) < eps && fabs(B.Y - C.Y) < eps) return false;
  if ((A.X - B.X) * (B.X - C.X) < 0) return false;
  if ((A.Y - B.Y) * (B.Y - C.Y) < 0) return false;
  return true;
}
double Dist(Point A, Point B) {
  return sqrt((A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y));
}
vector<Edge> G[100];
void Add(int S, int T, double Dist) {
  G[S].push_back((Edge){T, Dist});
  G[T].push_back((Edge){S, Dist});
}
double Dijkstra(int S, int T) {
  static double Dist[100];
  for (int i = 0; i < 100; i++) Dist[i] = (i == S) ? 0 : inf;
  static bool Flag[100];
  memset(Flag, 0, sizeof(Flag));
  priority_queue<Node> All;
  All.push((Node){S, 0});
  while (!Flag[T]) {
    int V = All.top().Number;
    All.pop();
    if (Flag[V]) continue;
    Flag[V] = true;
    for (int i = 0; i < G[V].size(); i++) {
      int U = G[V][i].Data;
      if (Dist[V] + G[V][i].Weight < Dist[U]) {
        Dist[U] = Dist[V] + G[V][i].Weight;
        All.push((Node){U, Dist[U]});
      }
    }
  }
  return Dist[T];
}
int main() {
  Point S, T;
  S.Get();
  T.Get();
  int N;
  scanf("%d", &N);
  static Point P[100];
  for (int i = 0; i < N; i++) P[i].Get();
  P[N] = P[0];
  int M = 2;
  static Data Q[100];
  Q[0] = (Data){S, N, 0};
  Q[1] = (Data){T, N + 1, 0};
  for (int i = 0; i < N; i++) {
    Point A = P[i], B = P[i + 1], O = Cross(A, B, S, T);
    if (On(A, O, B) && On(S, O, T)) {
      Add(i, N + M, Dist(A, O));
      Add((i + 1) % N, N + M, Dist(B, O));
      Q[M] = (Data){O, N + M, 1};
      M++;
    } else
      Add(i, (i + 1) % N, Dist(A, B));
  }
  for (int i = 0; i < N; i++)
    if (On(S, P[i], T)) {
      bool Flag = (F(S, T, P[i + 1]) * F(S, T, i ? P[i - 1] : P[N - 1]) < 0);
      Q[M] = (Data){P[i], N + M, Flag};
      M++;
    }
  sort(Q, Q + M);
  bool Inside = false;
  for (int i = 1; i < M; i++) {
    Add(Q[i - 1].Num, Q[i].Num, Dist(Q[i - 1].O, Q[i].O) * (Inside + 1));
    if (Q[i].Change) Inside = !Inside;
  }
  printf("%0.10lf\n", Dijkstra(N, N + 1));
  return 0;
}
