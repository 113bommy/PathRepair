#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 200000;
const int K_MAX = 5;
const int P_MAX = 120;
int n, k;
vector<int> all[P_MAX + 2];
int cntPerm;
int getIndex(vector<int> &p) {
  return lower_bound(all + 1, all + cntPerm + 1, p) - all;
}
int comp[P_MAX + 2][P_MAX + 2];
void precalc() {
  vector<int> p(k);
  for (int i = 0; i < k; i++) p[i] = i;
  do {
    all[++cntPerm] = p;
  } while (next_permutation(p.begin(), p.end()));
  for (int a = 1; a <= cntPerm; a++)
    for (int b = 1; b <= cntPerm; b++) {
      vector<int> aux(k);
      for (int i = 0; i < k; i++) aux[i] = all[a][all[b][i]];
      comp[a][b] = getIndex(aux);
    }
}
int input[N_MAX + 2];
int last[P_MAX + 2];
set<int> sorted;
int root[P_MAX + 2];
int subSize[P_MAX + 2];
void init() {
  for (int i = 1; i <= cntPerm; i++) {
    root[i] = i;
    subSize[i] = 1;
  }
}
int findRoot(int u) {
  if (root[u] == u) return u;
  return root[u] = findRoot(root[u]);
}
void join(int u, int v) {
  u = findRoot(u);
  v = findRoot(v);
  if (u == v) return;
  root[u] = v;
  subSize[v] += subSize[u];
}
void addPerm(int a) {
  if (findRoot(1) == findRoot(a)) return;
  for (int i = 1; i <= cntPerm; i++) join(i, comp[i][a]);
}
int main() {
  cin >> n >> k;
  precalc();
  for (int i = 1; i <= n; i++) {
    vector<int> p(k);
    for (int j = 0; j < k; j++) {
      cin >> p[j];
      p[j]--;
    }
    input[i] = getIndex(p);
  }
  for (int i = 1; i <= cntPerm; i++) last[i] = -1;
  sorted.insert(0);
  long long answer = 0;
  for (int r = 1; r <= n; r++) {
    sorted.erase(last[input[r]]);
    last[input[r]] = r;
    sorted.insert(last[input[r]]);
    init();
    answer += 1 * (r - *sorted.rbegin());
    for (set<int>::reverse_iterator it = sorted.rbegin(); *it != 0; it++) {
      addPerm(input[*it]);
      answer += subSize[findRoot(1)] * (*it - *next(it));
    }
  }
  cout << answer << "\n";
  return 0;
}
