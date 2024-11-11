#include <bits/stdc++.h>
using namespace std;
int n, p;
pair<int, int> nex[1005];
int color[1005], in[1005];
int Res[1005][3];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    nex[i] = make_pair(-1, -1);
    color[i] = in[i] = 0;
  }
  int u, v, w;
  for (int i = 1; i <= p; i++) {
    cin >> u >> v >> w;
    in[v] = 1;
    nex[u] = make_pair(v, w);
  }
  int Ans = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 1 || color[i] == 1 || nex[i].first == -1) {
      continue;
    }
    int Min = nex[i].second, vt = i;
    bool flag = true;
    while (nex[vt].first != -1) {
      Min = min(Min, nex[vt].second);
      if (color[vt] == 1) {
        flag = false;
        break;
      }
      color[vt] = 1;
      vt = nex[vt].first;
    }
    if (flag) {
      Ans++;
      Res[Ans][0] = i;
      Res[Ans][1] = vt;
      Res[Ans][2] = Min;
    }
  }
  cout << Ans << '\n';
  for (int i = 1; i <= Ans; i++) {
    cout << Res[i][0] << ' ' << Res[i][1] << ' ' << Res[i][2] << '\n';
  }
  return 0;
}
