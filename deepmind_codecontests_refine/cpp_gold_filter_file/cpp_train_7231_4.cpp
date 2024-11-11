#include <bits/stdc++.h>
using namespace std;
struct Inter {
  int d;
  int f;
  int id;
  int k;
  Inter(){};
  bool operator<(const Inter& i) const {
    if (d != i.d) return d < i.d;
    if (f != i.f) return f < i.f;
    return id < i.id;
  }
};
int N, M;
Inter notes[100001];
Inter gens[100001];
int ans[100001];
map<int, vector<pair<int, int> > > ls_ends;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &notes[i].d, &notes[i].f);
    notes[i].id = i;
  }
  sort(notes + 1, notes + N + 1);
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    scanf("%d%d%d", &gens[i].d, &gens[i].f, &gens[i].k);
    gens[i].id = i;
  }
  sort(gens + 1, gens + M + 1);
  int i = 1;
  for (int part = 1; part <= N; part++) {
    while ((i <= M) && (gens[i].d <= notes[part].d)) {
      ls_ends[gens[i].f].push_back(make_pair(gens[i].k, gens[i].id));
      i++;
    }
    map<int, vector<pair<int, int> > >::iterator to_rem =
        ls_ends.lower_bound(notes[part].f);
    if (to_rem == ls_ends.end()) {
      printf("NO\n");
      exit(0);
    }
    vector<pair<int, int> >& ls_possibles = to_rem->second;
    ans[notes[part].id] = ls_possibles.back().second;
    ls_possibles.back().first--;
    if (!ls_possibles.back().first) ls_possibles.pop_back();
    if (ls_possibles.empty()) ls_ends.erase(to_rem);
  }
  printf("YES\n");
  for (i = 1; i < N; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[N]);
  return 0;
}
