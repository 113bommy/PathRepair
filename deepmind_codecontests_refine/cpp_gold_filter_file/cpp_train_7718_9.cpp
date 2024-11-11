#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 1;
vector<int> g[MAXN], _g[MAXN];
bool was[MAXN];
int color[MAXN];
int input_size[MAXN];
vector<int> order;
vector<int> who[MAXN];
vector<int> upper_comp;
void dfs_order(int v) {
  if (was[v]) return;
  was[v] = 1;
  for (int u : g[v]) {
    dfs_order(u);
  }
  order.push_back(v);
}
void dfs_color(int v, int cur_color) {
  if (was[v]) return;
  was[v] = 1;
  color[v] = cur_color;
  who[cur_color].push_back(v);
  for (int u : _g[v]) {
    dfs_color(u, cur_color);
  }
}
void _delete(int top) {
  assert(who[color[top]].back() == top);
  who[color[top]].pop_back();
  for (int u : g[top]) {
    if (color[u] != color[top]) {
      input_size[color[u]]--;
      if (input_size[color[u]] == 0) {
        upper_comp.push_back(color[u]);
      }
    }
  }
}
int ask(int top, int cand) {
  cout << "? " << top + 1 << " " << cand + 1 << endl;
  int ans;
  cin >> ans;
  assert(ans != -1);
  if (ans == 1) {
    return top;
  }
  return cand;
}
int main(int argc, const char* argv[]) {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%i %i", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    _g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    dfs_order(i);
  }
  assert(((int)(order.size())) == n);
  memset(was, 0, sizeof was);
  int cnt_color = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!was[order[i]]) {
      dfs_color(order[i], cnt_color++);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int u : g[i]) {
      if (color[i] != color[u]) {
        input_size[color[u]]++;
      }
    }
  }
  for (int i = 0; i < cnt_color; i++) {
    if (input_size[i] == 0) {
      upper_comp.push_back(i);
    }
  }
  int top = who[upper_comp.back()].back();
  while (upper_comp.size() > 1) {
    int ind_cand_size = ((int)(upper_comp.size())) - 1;
    while (upper_comp[ind_cand_size] == color[top]) {
      ind_cand_size--;
      assert(ind_cand_size >= 0);
    }
    if (who[upper_comp[ind_cand_size]].size() == 0) {
      swap(upper_comp[ind_cand_size], upper_comp.back());
      upper_comp.pop_back();
      continue;
    }
    int next_cand = who[upper_comp[ind_cand_size]].back();
    int new_top = ask(top, next_cand);
    _delete(top + next_cand - new_top);
    top = new_top;
    ;
  }
  cout << "! " << top + 1 << endl;
  return 0;
}
