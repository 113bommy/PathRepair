#include <bits/stdc++.h>
using namespace std;
bitset<100014> ck[45];
vector<int> v;
string name[50];
int n, m, cnt, bcnt, bf, best, p[54], er;
bool c[50][50];
vector<pair<int, int> > sorted;
void bfs(int h) {
  bool nt = 0;
  if (h > cnt) {
    best = max(best, (int)v.size());
    return;
  }
  for (int i = 0; i < v.size(); i++)
    if (!c[v[i]][h]) nt = 1;
  if (!nt) {
    v.push_back(h);
    bfs(h + 1);
    v.pop_back();
  }
  if (v.size() + cnt - h > best) bfs(h + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      if (bf == 2) bcnt++;
      bf = 1;
    } else {
      string b;
      cin >> b;
      int fd = 0;
      for (int i = 0; i <= cnt; i++)
        if (name[i] == b) fd = i;
      if (!fd) cnt++, name[cnt] = b, fd = cnt;
      ck[fd][bcnt] = 1;
      bf = 2;
    }
  }
  for (int i = 1; i <= cnt; i++)
    for (int j = i; j <= cnt; j++)
      if ((ck[i] & ck[j]).count() == 0) c[i][j] = c[j][i] = 1;
  bfs(1);
  cout << best;
  return 0;
}
