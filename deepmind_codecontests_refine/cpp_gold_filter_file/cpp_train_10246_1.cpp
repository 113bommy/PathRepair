#include <bits/stdc++.h>
using namespace std;
int n;
list<pair<int, int> > estradas[100010];
list<int> candidates;
int nCandidates;
int checked[100010];
int dfs(int candidate, int ruim) {
  int problem = 0;
  list<pair<int, int> >::iterator it;
  checked[candidate] = 1;
  for (it = estradas[candidate].begin(); it != estradas[candidate].end();
       it++) {
    if (!checked[(*it).first]) {
      problem |= dfs((*it).first, (*it).second);
    }
  }
  if (problem == 1) return 1;
  if (ruim) {
    nCandidates++;
    candidates.push_back(candidate);
    return 1;
  }
  return 0;
}
int main() {
  int a, b, c;
  scanf("%d\n", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d\n", &a, &b, &c);
    c--;
    estradas[a].push_back(make_pair(b, c));
    estradas[b].push_back(make_pair(a, c));
  }
  dfs(1, 0);
  printf("%d\n", nCandidates);
  while (!candidates.empty()) {
    printf("%d ", candidates.front());
    candidates.pop_front();
  }
  putchar('\n');
}
