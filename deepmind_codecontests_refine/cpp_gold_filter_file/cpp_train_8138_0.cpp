#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, m;
int x[N];
long long res;
int step;
vector<int> g[N];
int pos[N];
int used[N];
void update(int p, bool add) {
  if (p < 1 || p >= m) return;
  if (used[p] == step) return;
  used[p] = step;
  int val = abs(pos[x[p]] - pos[x[p + 1]]);
  if (add)
    res += val;
  else
    res -= val;
}
void proc(int x, bool add) {
  for (int pos : g[x]) {
    update(pos - 1, add);
    update(pos, add);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", &x[i]);
  res = 0;
  for (int i = 1; i <= n; i++) pos[i] = i;
  for (int i = 1; i <= m; i++) g[x[i]].push_back(i);
  for (int i = 1; i < m; i++) res += abs(pos[x[i]] - pos[x[i + 1]]);
  cout << res << " ";
  step = 0;
  for (int i = 2; i <= n; i++) {
    step++;
    proc(i, 0);
    proc(i - 1, 0);
    step++;
    swap(pos[i], pos[i - 1]);
    proc(i, 1);
    proc(i - 1, 1);
    cout << res << " ";
  }
  return 0;
}
