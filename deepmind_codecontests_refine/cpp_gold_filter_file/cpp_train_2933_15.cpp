#include <bits/stdc++.h>
using namespace std;
int id[555][2], num[555], pri[555][2];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= 520; i++) pri[i][0] = pri[i][1] = 1e9 + 10;
  for (int i = 1; i <= n; i++) {
    int v, x, res = 0;
    cin >> v;
    for (int j = 0; j < v; j++) cin >> x, res |= (1 << (x - 1));
    num[res]++;
  }
  for (int i = 1; i <= m; i++) {
    int w, v, x, res = 0;
    cin >> w >> v;
    for (int j = 0; j < v; j++) cin >> x, res |= (1 << (x - 1));
    int t = i;
    if (w < pri[res][0]) swap(w, pri[res][0]), swap(t, id[res][0]);
    if (w < pri[res][1]) swap(w, pri[res][1]), swap(t, id[res][1]);
  }
  int ans = -1, cost = 2e9 + 10, peo1 = 0, peo2 = 0;
  for (int mk1 = 0; mk1 < 512; mk1++) {
    for (int mk2 = 0; mk2 < 512; mk2++) {
      if (!id[mk1][0] || !id[mk2][0]) continue;
      if (mk1 == mk2) {
        int temp = 0;
        if (id[mk1][1] == 0) continue;
        for (int mk3 = 0; mk3 < 512; mk3++) {
          if (((mk1 | mk2) & mk3) == mk3) {
            temp += num[mk3];
          }
        }
        if (temp > ans) {
          ans = temp;
          cost = pri[mk1][0] + pri[mk1][1], peo1 = id[mk1][0],
          peo2 = id[mk1][1];
        } else if (temp == ans)
          if (pri[mk1][0] + pri[mk1][1] < cost)
            cost = pri[mk1][0] + pri[mk1][1], peo1 = id[mk1][0],
            peo2 = id[mk1][1];
      } else {
        int temp = 0;
        for (int mk3 = 0; mk3 < 512; mk3++) {
          if (((mk1 | mk2) & mk3) == mk3) {
            temp += num[mk3];
          }
        }
        if (temp > ans) {
          ans = temp;
          peo1 = id[mk1][0], peo2 = id[mk2][0];
          cost = pri[mk1][0] + pri[mk2][0], peo1 = id[mk1][0],
          peo2 = id[mk2][0];
        } else if (temp == ans)
          if (pri[mk1][0] + pri[mk2][0] < cost)
            cost = pri[mk1][0] + pri[mk2][0], peo1 = id[mk1][0],
            peo2 = id[mk2][0];
      }
    }
  }
  cout << peo1 << ' ' << peo2 << endl;
}
