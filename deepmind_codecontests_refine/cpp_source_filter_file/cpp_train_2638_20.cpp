#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
int h, m, n;
long long ans;
map<int, int> id;
int pat[200010], tot;
set<int> tree[200010];
int ord[200010];
vector<int> rec[200010];
int main() {
  ios::sync_with_stdio(false);
  char op;
  int x, y;
  cin >> h >> m >> n;
  ans = 0;
  tot = 0;
  memset(pat, -1, sizeof(pat));
  memset(ord, 0, sizeof(ord));
  for (int i = (0); i < (h); i++)
    if (pat[i] == -1) {
      for (int j = i, t = 0; pat[j] == -1; j = (j + m) % h, t++) {
        pat[j] = tot;
        ord[j] = t;
        rec[tot].push_back(j);
        tree[tot].insert(t);
      }
      tot++;
    }
  while (n--) {
    cin >> op;
    if (op == '+') {
      cin >> x >> y;
      set<int>::iterator it = tree[pat[y]].lower_bound(ord[y]);
      if (it == tree[pat[y]].end()) it = tree[pat[y]].begin();
      int tmp = (*it);
      if (ord[y] < tmp)
        ans += (tmp - ord[y] - 1);
      else {
        int st = rec[pat[y]].size();
        ans += st - ord[y] + tmp - 1;
      }
      id[x] = rec[pat[y]][tmp];
      tree[pat[y]].erase(it);
    } else {
      cin >> x;
      int tmp = id[x];
      tree[pat[tmp]].insert(ord[tmp]);
    }
  }
  cout << ans << endl;
  return 0;
}
