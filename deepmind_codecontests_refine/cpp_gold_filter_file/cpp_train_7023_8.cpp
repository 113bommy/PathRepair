#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
const int MAXN = 1200;
int N, M;
char table[MAXN][MAXN];
vector<vector<int>> check(int col, const vector<vector<int>>& groups) {
  vector<vector<int>> ngroups;
  for (const vector<int>& group : groups) {
    char last = '\0';
    vector<int> ngroup;
    for (int line : group) {
      if (table[line][col] < last) {
        return vector<vector<int>>();
      } else if (last != '\0' && last != table[line][col]) {
        ngroups.push_back(ngroup);
        ngroup.clear();
      }
      ngroup.push_back(line);
      last = table[line][col];
    }
    ngroups.push_back(ngroup);
  }
  return ngroups;
}
int main() {
  scanf("%d%d ", &N, &M);
  for (int i = 0; i < (N); ++i) {
    gets(table[i]);
  }
  int n = 0;
  vector<vector<int>> groups;
  groups.emplace_back();
  for (int i = 0; i < (N); ++i) groups.back().push_back(i);
  for (int i = 0; i < (M); ++i) {
    vector<vector<int>> ngroups = check(i, groups);
    if (ngroups.empty()) {
      ++n;
    } else {
      groups = ngroups;
    }
  }
  printf("%d\n", n);
  return 0;
}
