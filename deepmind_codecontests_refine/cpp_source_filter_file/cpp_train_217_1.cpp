#include <bits/stdc++.h>
using namespace std;
int father[100005];
struct A {
  int a, b, con;
} all[100005];
vector<pair<int, int> > road[100005];
bool is[100005] = {0};
bool have[100005] = {0};
int F(int now) {
  if (father[now] == now)
    return now;
  else {
    father[now] = F(father[now]);
    return father[now];
  }
}
bool com(A a, A b) { return a.con < b.con; }
pair<int, int> Find(int now) {
  have[now] = 1;
  int N = road[now].size(), i, big = 0, ok = is[now];
  pair<int, int> t;
  for (i = 0; i < N; i++) {
    if (have[road[now][i].first] == 0) {
      t = Find(road[now][i].first);
      ok = ok || t.second;
      if (t.second) big = max(t.first, max(big, road[now][i].second));
    }
  }
  return make_pair(big, ok);
}
int main() {
  int N, M, K, ans, t, i;
  scanf("%d %d %d", &N, &M, &K);
  for (i = 0; i < K; i++) {
    scanf("%d", &t);
    is[t] = 1;
  }
  for (i = 0; i < M; i++) scanf("%d %d %d", &all[i].a, &all[i].b, &all[i].con);
  sort(all, all + M, com);
  for (i = 1; i <= N; i++) father[i] = i;
  for (i = 0; i < M; i++) {
    if (F(all[i].a) != F(all[i].b)) {
      father[F(all[i].a)] = F(all[i].b);
      road[all[i].a].push_back(make_pair(all[i].b, all[i].con));
      road[all[i].b].push_back(make_pair(all[i].a, all[i].con));
    }
  }
  for (i = 1; i <= N; i++) {
    if (is[i]) {
      ans = Find(1).first;
      break;
    }
  }
  for (i = 1; i <= K; i++) printf("%d ", ans);
  return 0;
}
