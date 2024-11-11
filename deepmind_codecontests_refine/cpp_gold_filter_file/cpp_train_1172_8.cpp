#include <bits/stdc++.h>
using namespace std;
struct room {
  int a, b, c;
};
struct rul {
  int a, b, dollars;
};
int main() {
  int n, res = 0, m;
  room kom[500];
  rul rulon[500];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> kom[i].a >> kom[i].b >> kom[i].c;
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> rulon[i].a >> rulon[i].b >> rulon[i].dollars;
  for (int i = 0; i < n; i++) {
    int minmoney = 1000000, P = 2 * (kom[i].a + kom[i].b);
    for (int j = 0; j < m; j++) {
      int lol = rulon[j].a / kom[i].c;
      if (lol == 0) continue;
      int numpol = P % rulon[j].b == 0 ? P / rulon[j].b : P / rulon[j].b + 1;
      int numrul = numpol % lol == 0 ? numpol / lol : numpol / lol + 1;
      int money = numrul * rulon[j].dollars;
      if (money < minmoney) minmoney = money;
    }
    res += minmoney;
  }
  cout << res;
}
