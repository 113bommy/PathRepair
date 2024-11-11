#include <bits/stdc++.h>
using namespace std;
int n, m, sfr, ans[100009];
vector<int> bar[100009];
struct node {
  int l, r, c, id;
  bool operator<(const node &b) const { return r > b.r; }
} a[100009];
int main() {
  int i;
  cin >> n >> m;
  ;
  for (i = (1); i <= (m); i++) {
    cin >> a[i].r >> a[i].c;
    a[i].l = n - a[i].c + 1, a[i].id = i;
    bar[a[i].l].push_back(i);
  }
  priority_queue<node> q;
  ;
  for (i = (1); i <= (n); i++) {
    for (auto j : bar[i]) q.push(a[j]);
    while (!q.empty() && q.top().r < i) q.pop();
    if (!q.empty()) ans[++sfr] = q.top().id, q.pop();
  }
  cout << sfr << endl;
  ;
  for (i = (1); i <= (sfr); i++) printf("%d%c", ans[i], i == sfr ? '\n' : ' ');
}
