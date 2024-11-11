#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int inf = 1e9;
int h, m, n;
set<pair<long long int, int> > gp[N];
vector<int> quem[N];
int to[N];
pair<long long int, int> el[N];
int vis[N];
map<int, int> too;
long long int ans = 0;
int on = 0;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d %d %d", &h, &m, &n);
  m %= h;
  int now = 0;
  for (int i = 0; i < h; i++) {
    if (vis[i] == 1) continue;
    long long int hcur = i;
    int ecur = i;
    set<pair<long long int, int> > cur;
    int x = 0;
    while (vis[ecur] < 1) {
      quem[on].push_back(ecur);
      to[ecur] = on;
      vis[ecur]++;
      gp[on].insert(pair<long long int, int>(hcur, x));
      el[ecur] = pair<long long int, int>(hcur, x);
      hcur += m;
      ecur = (ecur + m);
      if (ecur >= h) ecur -= h;
      x++;
    }
    on++;
  }
  while (n--) {
    char op;
    int id;
    int hshh;
    scanf(" %c %d", &op, &id);
    if (op == '+') {
      scanf("%d", &hshh);
      int group = to[hshh];
      long long int hsh = hshh;
      int pos = el[hsh].second;
      hsh = el[hsh].first;
      auto it = gp[group].lower_bound(pair<long long int, int>(hsh, -inf));
      if (it == gp[group].end()) {
        it = gp[group].lower_bound(pair<long long int, int>(0, -inf));
        ans += (int)quem[on].size() - pos + (*it).second;
      } else {
        ans += (*it).second - pos;
      }
      too[id] = quem[group][(*it).second];
      gp[group].erase(it);
    } else {
      int group = to[too[id]];
      gp[group].insert(el[too[id]]);
      too.erase(id);
    }
  }
  cout << ans << '\n';
  return 0;
}
