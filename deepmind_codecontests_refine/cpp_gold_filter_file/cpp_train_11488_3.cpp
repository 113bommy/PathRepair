#include <bits/stdc++.h>
using namespace std;
struct dl {
  int buy, sell, remain;
} item[1010][1010];
struct dl1 {
  int cost, amount;
} e[110];
int N, K, M;
bool cmp(dl1 a, dl1 b) { return a.cost > b.cost; };
int exchange(int ii, int jj) {
  for (int i = 0; i < M; ++i) {
    e[i].cost = item[jj][i].sell - item[ii][i].buy;
    e[i].amount = item[ii][i].remain;
  }
  sort(e, e + M, cmp);
  int ind = 0, k = K, money = 0;
  while (ind < M && k > 0) {
    if (e[ind].cost < 0) {
      ++ind;
      continue;
    }
    if (k <= e[ind].amount) {
      money += k * e[ind].cost;
      k = 0;
    } else {
      money += e[ind].amount * e[ind].cost;
      k -= e[ind++].amount;
    }
  }
  return money;
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < N; ++i) {
    getchar();
    string s;
    getline(cin, s);
    for (int j = 0; j < M; ++j)
      scanf("%d%d%d", &item[i][j].buy, &item[i][j].sell, &item[i][j].remain);
  }
  int ans = -0x7f7f7f7f;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (i != j) {
        int tmp = exchange(i, j);
        ans = max(ans, tmp);
      }
  cout << ans;
  return 0;
}
