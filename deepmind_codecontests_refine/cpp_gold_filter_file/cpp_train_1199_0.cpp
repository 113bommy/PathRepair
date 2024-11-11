#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = (double)1e-8;
const int mod = (int)1000000007;
const int maxn = (int)1e5 + 5;
int n, tp[105], tb[105], to, x;
vector<pair<int, int> > b[105];
pair<int, int> pos[105];
string st[105];
void dzen(int v, int p) {
  if (tb[v]) return;
  tb[v] = 1;
  pos[v] = make_pair(p, v);
  ;
  for (int i = (0); i < (b[v].size()); i++) {
    if (tp[b[v][i].first]) continue;
    tp[b[v][i].first] = 1;
    int to = b[v][i].first;
    int x = b[v][i].second;
    for (int j = (0); j < (st[to].size()); j++) {
      dzen(st[to][j] - 'a', p + j - x);
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    cin >> st[i];
    for (int j = (0); j < (st[i].size()); j++) {
      b[st[i][j] - 'a'].push_back(make_pair(i, j));
    }
  }
  memset((tp), 0, sizeof(tp));
  memset((tb), 0, sizeof(tb));
  memset(pos, -1, sizeof pos);
  int cnt = -1;
  for (int i = (0); i <= (25); i++) {
    if (tb[i] || (int)b[i].size() == 0) continue;
    cnt++;
    dzen(i, cnt * 100);
  }
  sort(pos, pos + 26);
  for (int i = (0); i <= (25); i++) {
    if (pos[i].second == -1) continue;
    cout << char('a' + pos[i].second);
  }
  return 0;
}
