#include <bits/stdc++.h>
using namespace std;
struct team {
  long long p, w;
  int ind;
};
bool cmp(const team& a, const team& b) {
  if (a.p == b.p) return a.ind < b.ind;
  return a.p > b.p;
}
class tcmp {
 public:
  bool operator()(const team& a, const team& b) {
    return (a.w - a.p) > (b.w - b.p);
  }
};
int main() {
  int N;
  scanf("%d", &N);
  team t[N];
  for (int i = 0; i < N; i++) {
    scanf("%lld%lld", &t[i].p, &t[i].w);
    t[i].ind = i;
  }
  sort(t, t + N, cmp);
  int lind;
  for (int i = 0; i < N; i++)
    if (t[i].ind == 0) lind = i;
  priority_queue<team, vector<team>, tcmp> Q;
  int ind = 0;
  while (t[ind].p > t[lind].p) {
    Q.push(t[ind]);
    ind++;
  }
  int answ = lind;
  long long used = 0;
  while (!Q.empty()) {
    team tact = Q.top();
    Q.pop();
    if (used <= t[lind].p) used += (tact.w - tact.p + 1);
    while (ind < N && t[lind].p - used < t[ind].p) {
      if (t[ind].ind != 0) Q.push(t[ind]);
      ind++;
    }
    if (t[lind].p - used >= 0) answ = min(answ, (int)Q.size());
  }
  printf("%d\n", answ + 1);
  return 0;
}
