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
inline T sqr(T X) {
  return X * X;
}
namespace Poor {
const int MaxiN = 200005;
int N, M;
long long Answer;
int Q[MaxiN];
pair<pair<int, int>, int> Wall[MaxiN];
vector<pair<pair<int, int>, int> > Real;
vector<pair<int, pair<int, int> > > Event;
void Pretreat() {
  priority_queue<pair<int, int> > pq;
  while (!pq.empty()) pq.pop();
  int LastWall = 0;
  Real.clear();
  sort(Wall, Wall + N);
  for (int i = 0; i < N; ++i) {
    pq.push(make_pair(-Wall[i].second, i));
    while (!pq.empty() && (i == N - 1 || LastWall < Wall[i + 1].first.first)) {
      pair<int, int> Cur = pq.top();
      pq.pop();
      if (Wall[Cur.second].first.second <= LastWall) continue;
      int NextWall = Wall[Cur.second].first.second;
      if (i < N - 1) checkmin(NextWall, Wall[i + 1].first.first);
      checkmax(LastWall, Wall[Cur.second].first.first);
      Real.push_back(
          make_pair(make_pair(LastWall, NextWall), Wall[Cur.second].second));
      LastWall = NextWall;
      if (NextWall < Wall[i + 1].first.second) pq.push(Cur);
    }
  }
  Answer = 0;
  for (typeof(Real.begin()) it = Real.begin(); it != Real.end(); ++it) {
    int T1 = it->second - it->first.first;
    Event.push_back(
        make_pair(max(T1, 0), make_pair(-it->first.first + it->second, -1)));
    int T2 = it->second - it->first.second;
    Event.push_back(
        make_pair(max(T2, 0), make_pair(it->first.second - it->second, 1)));
  }
  sort(Event.begin(), Event.end());
  reverse(Event.begin(), Event.end());
}
void Run() {
  scanf("%d%d", &M, &N);
  for (int i = 0; i < N; ++i)
    scanf("%d%d%d", &Wall[i].first.first, &Wall[i].first.second,
          &Wall[i].second);
  Pretreat();
  long long Coef = 0;
  for (int i = 0; i < M; ++i) {
    scanf("%d", &Q[i]);
    while (!Event.empty() && Event.back().first <= Q[i]) {
      Answer += Event.back().second.first;
      Coef += Event.back().second.second;
      Event.pop_back();
    }
    printf("%d\n", (int)(Answer + Coef * Q[i]));
  }
}
}  // namespace Poor
int main(int argc, char **argv) {
  Poor::Run();
  return 0;
}
