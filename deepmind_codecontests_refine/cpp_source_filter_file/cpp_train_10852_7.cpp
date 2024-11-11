#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct state {
  int id, v;
  state(int ID, int V) { id = ID, v = V; }
};
bool operator<(state A, state B) {
  return A.v < B.v || (A.v == B.v && A.id < B.id);
}
int n, m, data[maxn];
priority_queue<state> Q;
vector<pair<int, int> > V;
vector<int> rem;
void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &data[i]);
}
bool solve() {
  for (int i = 1; i <= n; i++) Q.push(state(i, data[i]));
  while (true) {
    if (Q.empty() || Q.top().v == 0) break;
    rem.clear();
    int i = Q.top().id;
    Q.pop();
    while (data[i]--) {
      if (Q.empty() || Q.top().v == 0) return false;
      int j = Q.top().id;
      Q.pop();
      data[j]--;
      rem.push_back(j);
      V.push_back(make_pair(i, j));
    }
    data[i] = 0;
    for (int k = 0; k < (int)rem.size(); k++)
      Q.push(state(rem[k], data[rem[k]]));
  }
  for (int i = 1; i <= n; i++)
    if (data[i] != 0) return false;
  printf("YES\n");
  printf("%d\n", V.size());
  for (int i = 0; i < (int)V.size(); i++)
    printf("%d %d\n", V[i].first, V[i].second);
  return true;
}
int main() {
  input();
  if (!solve()) printf("NO\n");
  return 0;
}
