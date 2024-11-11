#include <bits/stdc++.h>
using namespace std;
int N, Q, T[3 * 1000005], O[1000005], Pos, Start, End, Val, Size = 0;
int K, X, Y;
pair<int, int> P[1000005];
map<long long, int> last;
vector<pair<int, int>> Poly;
struct elements {
  long long angle;
  int pos, next;
} v[1000005];
struct queries {
  int s, e, pos;
} q[1000005];
bool cond_el(elements a, elements b) { return a.next < b.next; }
bool cond_q(queries a, queries b) { return a.e < b.e; }
void DFS(int node, int s, int e) {
  if (s == e)
    T[node] = 1;
  else {
    int mid = (s + e) >> 1;
    DFS(2 * node, s, mid);
    DFS(2 * node + 1, mid + 1, e);
    T[node] = T[2 * node] + T[2 * node + 1];
  }
}
void Update(int node, int s, int e) {
  if (s == e)
    T[node] = 0;
  else {
    int mid = (s + e) >> 1;
    if (Pos <= mid)
      Update(2 * node, s, mid);
    else
      Update(2 * node + 1, mid + 1, e);
    T[node] = T[2 * node] + T[2 * node + 1];
  }
}
void Query(int node, int s, int e) {
  if (Start <= s && e <= End)
    Val += T[node];
  else {
    int mid = (s + e) >> 1;
    if (Start <= mid) Query(2 * node, s, mid);
    if (End > mid) Query(2 * node + 1, mid + 1, e);
  }
}
int main() {
  scanf("%d", &N);
  P[1].first = 1;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &K);
    P[i].second = P[i].first + K - 1;
    P[i + 1].first = P[i].first + K;
    Poly.clear();
    for (int j = 1; j <= K; j++) scanf("%d%d", &X, &Y), Poly.push_back({X, Y});
    for (int j = 0; j < K; j++) {
      v[++Size].pos = Size;
      v[Size].next = 1000005 - 1;
      long long ang =
          10000000000000 *
          atan2((1.0 * Poly[j].second - 1.0 * Poly[(j + 1) % K].second),
                (1.0 * Poly[j].first - 1.0 * Poly[(j + 1) % K].first));
      v[Size].angle = ang;
      if (last.find(ang) != last.end()) v[last[ang]].next = Size;
      last[ang] = Size;
    }
  }
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    q[i].pos = i;
    scanf("%d%d", &q[i].s, &q[i].e);
  }
  sort(v + 1, v + 1 + Size, cond_el);
  sort(q + 1, q + 1 + Q, cond_q);
  DFS(1, 1, Size);
  int pos = 1;
  for (int i = 1; i <= Q; i++) {
    while (pos <= Size && v[pos].next <= P[q[i].e].second) {
      Pos = v[pos++].pos;
      Update(1, 1, Size);
    }
    Start = P[q[i].s].first, End = P[q[i].e].second;
    Val = 0;
    Query(1, 1, Size);
    O[q[i].pos] = Val;
  }
  for (int i = 1; i <= Q; i++) printf("%d\n", O[i]);
  return 0;
}
