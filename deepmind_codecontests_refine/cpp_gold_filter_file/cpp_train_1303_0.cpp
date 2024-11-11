#include <bits/stdc++.h>
int Pre[100001], Suc[100001], Dead[100001], N, M, Pos[100001], Speed[100001],
    CurrentTurn;
long long Passed[100001], CurrentTime, CatchTime[100001];
int Heap[100001], Ref[100001], L;
inline void Swap(int u, int v) {
  std::swap(Heap[u], Heap[v]);
  Ref[Heap[u]] = u;
  Ref[Heap[v]] = v;
}
inline void PositionUpdate(int x) {
  if (Passed[x] < CurrentTime - (x > CurrentTurn)) {
    Pos[x] =
        (Pos[x] + (CurrentTime - (x > CurrentTurn) - Passed[x]) % M * Speed[x] -
         1) %
            M +
        1;
    Passed[x] = CurrentTime - (x > CurrentTurn);
  }
}
inline int DisN(int x, int y) { return y - x <= 0 ? y - x + N : y - x; }
inline int DisM(int x, int y) { return y - x < 0 ? y - x + M : y - x; }
inline void CatchUpdate(int x) {
  PositionUpdate(x);
  PositionUpdate(Suc[x]);
  int Dist = DisM(Pos[x], Pos[Suc[x]]), NeedTime;
  if (Speed[x] <= Speed[Suc[x]]) {
    CatchTime[x] =
        DisN(CurrentTurn, x) < DisN(CurrentTurn, Suc[x]) && Speed[x] >= Dist
            ? 1
            : 1LL << 60;
    return;
  }
  if (DisN(CurrentTurn, x) < DisN(CurrentTurn, Suc[x]))
    NeedTime = std::max(1, (Dist + Speed[x] - 1 - (Speed[Suc[x]] << 1)) /
                               (Speed[x] - Speed[Suc[x]]));
  else
    NeedTime =
        (Dist + Speed[x] - Speed[Suc[x]] - 1) / (Speed[x] - Speed[Suc[x]]);
  CatchTime[x] = CurrentTime - (CurrentTurn < x) + NeedTime;
}
inline bool Compare(int x, int y) {
  if (Dead[x]) return false;
  if (Dead[y]) return true;
  return std::make_pair(CatchTime[x], x) < std::make_pair(CatchTime[y], y);
}
void Pushup(int p) {
  int w = Heap[p];
  while (p > 1 && Compare(w, Heap[p >> 1])) {
    Heap[p] = Heap[p >> 1];
    Ref[Heap[p]] = p;
    p >>= 1;
  }
  Heap[p] = w;
  Ref[w] = p;
}
void Pushdown(int p) {
  int w = Heap[p];
  while (p + p <= L) {
    int np = p + p;
    if (np < L && Compare(Heap[p << 1 | 1], Heap[p << 1])) np++;
    if (Compare(Heap[np], w)) {
      Heap[p] = Heap[np];
      Ref[Heap[p]] = p;
      p = np;
    } else {
      Heap[p] = w;
      Ref[w] = p;
      return;
    }
  }
  Heap[p] = w;
  Ref[w] = p;
}
void Insert(int x) {
  Heap[Ref[x] = ++L] = x;
  Pushup(L);
}
int Get() {
  int res = Heap[1];
  Heap[1] = Heap[L--];
  Ref[Heap[1]] = 1;
  Ref[res] = 0;
  if (L > 1) Pushdown(1);
  return res;
}
int main() {
  scanf("%d%d", &N, &M);
  CurrentTurn = N;
  for (int i = 1; i <= N; i++) scanf("%d%d", Pos + i, Speed + i);
  static int p[100001];
  for (int i = 1; i <= N; i++) p[i] = i;
  std::sort(p + 1, p + N + 1, [](int x, int y) { return Pos[x] < Pos[y]; });
  for (int i = 1; i < N; i++) {
    Suc[p[i]] = p[i + 1];
    Pre[p[i + 1]] = p[i];
  }
  Suc[p[N]] = p[1];
  Pre[p[1]] = p[N];
  for (int i = 1; i <= N; i++) {
    CatchUpdate(i);
    Insert(i);
  }
  while (1) {
    int Top = Get();
    if (CatchTime[Top] == 1LL << 60) break;
    CurrentTime = CatchTime[Top];
    CurrentTurn = Top - 1;
    if (Top == 1) {
      CurrentTime--;
      CurrentTurn = N;
    }
    int LastKill = Suc[Top], KillNum = 1;
    PositionUpdate(Top);
    PositionUpdate(LastKill);
    Dead[Suc[Top]] = 1;
    Pushdown(Ref[LastKill]);
    while (Suc[LastKill] != Top &&
           (PositionUpdate(Suc[LastKill]),
            DisM(Pos[Top], Pos[Suc[LastKill]]) <= Speed[Top])) {
      KillNum++;
      Dead[LastKill = Suc[LastKill]] = 1;
      Pushdown(Ref[LastKill]);
    }
    if (Top == 1) CurrentTime++;
    CurrentTurn = Top;
    PositionUpdate(Top);
    Speed[Top] = std::max(Speed[Top] - KillNum, 0);
    Suc[Top] = Suc[LastKill];
    if (Suc[Top] == Top) break;
    Pre[Suc[LastKill]] = Top;
    CatchUpdate(Pre[Top]);
    Pushup(Ref[Pre[Top]]);
    CatchUpdate(Top);
    Insert(Top);
  }
  int Count = std::count_if(Dead + 1, Dead + N + 1, [](int x) { return !x; });
  printf("%d\n", Count);
  for (int i = 1; i <= N; i++)
    if (!Dead[i]) printf("%d%c", i, --Count ? ' ' : '\n');
  return 0;
}
