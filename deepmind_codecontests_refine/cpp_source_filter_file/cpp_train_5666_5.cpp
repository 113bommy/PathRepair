#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct student {
  int ability, cost, idx;
} S[MAXN];
struct bug {
  int complexity, idx;
  bool operator<(const bug &rhs) const { return complexity < rhs.complexity; }
} B[MAXN];
struct compQ {
  bool operator()(const student &lhs, const student &rhs) const {
    return (lhs.cost == rhs.cost) ? (lhs.ability < rhs.ability)
                                  : (lhs.cost > rhs.cost);
  }
};
bool compS(student lhs, student rhs) { return lhs.ability < rhs.ability; }
int N, M, C, result[MAXN];
bool valid(int D) {
  priority_queue<student, vector<student>, compQ> Q;
  int cur = N;
  long long cost = 0;
  for (int i = M; i >= 1; i -= D) {
    while (cur && S[cur].ability >= B[i].complexity) Q.push(S[cur--]);
    if (Q.empty()) return false;
    student t = Q.top();
    Q.pop();
    cost += t.cost;
  }
  return (cost <= (long long)(C));
}
int main() {
  scanf("%d %d %d", &N, &M, &C);
  for (int i = 1; i <= M; ++i) {
    scanf("%d", &B[i].complexity);
    B[i].idx = i;
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &S[i].ability);
    S[i].idx = i;
  }
  for (int i = 1; i <= N; ++i) scanf("%d", &S[i].cost);
  sort(S + 1, S + N + 1, compS);
  sort(B + 1, B + M + 1);
  int lo = 1, hi = M, mid, res = -1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (valid(mid))
      hi = mid - 1, res = mid;
    else
      lo = mid + 1;
  }
  if (res == -1) {
    puts("NO");
    return 0;
  }
  priority_queue<student, vector<student>, compQ> Q;
  int cur = N;
  for (int i = M; i >= 1; i -= res) {
    while (cur && S[cur].ability >= B[i].complexity) Q.push(S[cur--]);
    if (Q.empty()) return false;
    student t = Q.top();
    Q.pop();
    for (int j = i; j > i - res; --j) result[B[j].idx] = t.idx;
  }
  puts("YES");
  for (int i = 1; i <= M; ++i) printf("%d ", result[i]);
  return 0;
}
