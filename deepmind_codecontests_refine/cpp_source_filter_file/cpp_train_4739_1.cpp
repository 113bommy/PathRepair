#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > ed;
vector<vector<int> > cost;
int ns[100005];
long long best[100005][2];
long long solve(int ind, bool come, int last) {
  if (best[ind][come] != -1) return best[ind][come];
  if (ns[ind] == 1 && last != -1) return best[ind][come] = 0;
  if (ns[ind] == 0) return best[ind][come] = 0;
  long long sum = 0;
  int c, c2;
  for (c = 0; c < ns[ind]; c++) {
    if (ed[ind][c] == last) continue;
    sum += solve(ed[ind][c], 1, ind) + (long long)cost[ind][c] +
           (long long)cost[ind][c];
  }
  if (come) return best[ind][come] = sum;
  long long ret = 1LL << 60;
  for (c = 0; c < ns[ind]; c++) {
    if (ed[ind][c] == last) continue;
    ret = min(ret, sum - best[ed[ind][c]][1] - (long long)cost[ind][c] +
                       solve(ed[ind][c], 0, ind));
  }
  return best[ind][come] = ret;
}
int main() {
  FILE *in = stdin;
  int c, c2;
  fscanf(in, "%d", &n);
  ed.resize(n);
  cost.resize(n);
  for (c = 0; c < n - 1; c++) {
    int t1, t2, t3;
    fscanf(in, "%d%d%d", &t1, &t2, &t3);
    t1--;
    t2--;
    ed[t1].push_back(t2);
    ed[t2].push_back(t1);
    cost[t1].push_back(t3);
    cost[t2].push_back(t3);
    ns[t1]++;
    ns[t2]++;
  }
  memset(best, -1, sizeof(best));
  int ret = solve(0, 0, -1);
  printf("%I64d\n", ret);
  return 0;
}
