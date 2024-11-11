#include <bits/stdc++.h>
using namespace std;
int cats[100005];
vector<int> tree[100001];
int n, m, res = 0;
void dfs(int current, int current_cats, int parent) {
  if (current_cats > m) return;
  int is_leave = 1;
  for (int i = 0; i < tree[current].size(); i++)
    if (tree[current][i] != parent) {
      is_leave = 0;
      if (cats[current] == 0) current_cats = 0;
      dfs(tree[current][i], current_cats + cats[tree[current][i]], current);
    }
  res = res + is_leave;
}
int main() {
  cin >> n >> m;
  int s = min(n, m);
  int t = max(n, m);
  t = t - s;
  t = t / 2;
  cout << s << t << endl;
}
