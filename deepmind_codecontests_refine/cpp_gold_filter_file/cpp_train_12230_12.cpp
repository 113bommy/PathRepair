#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXN = 1000006;
vector<int> T[MAXN];
vector<pair<int, int> > C[MAXN];
void no() {
  printf("IMPOSSIBLE\n");
  exit(0);
}
int NR;
vector<int> ANS;
int n, k;
int DFS(int must) {
  int r_max = -1, r_min = MAXN, l_min = MAXN, l_max = -1;
  int back = NR;
  NR++;
  if (C[back].empty() && must == back) {
    ANS.push_back(back);
    return back;
  }
  for (typeof((C[back]).begin()) it = (C[back]).begin(); it != (C[back]).end();
       ++it) {
    if (it->second == 0) {
      l_min = min(l_min, it->first);
      l_max = max(l_max, it->first);
    } else {
      r_min = min(r_min, it->first);
      r_max = max(r_max, it->first);
    }
  }
  if (r_min != MAXN && l_max != -1 && r_min <= l_max) no();
  if (r_min <= back || l_min <= back) no();
  int w = -1;
  if (l_max != -1) w = DFS(l_max);
  ANS.push_back(back);
  if (w >= r_min) no();
  if (w < max(must, r_max)) return DFS(max(r_max, must));
  return w;
}
void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < (k); ++i) {
    int a, b;
    char c[20];
    scanf(" %d %d %s", &a, &b, c);
    if (a >= b) no();
    C[a].push_back(pair<int, int>(b, c[0] == 'R' ? 1 : 0));
  }
  NR = 1;
  int w = DFS(n);
  if (w > n) no();
  for (int i = 0; i < (n); ++i) printf("%d ", ANS[i]);
}
int main() {
  int t = 1;
  for (int i = 0; i < (t); ++i) solve();
  return 0;
}
