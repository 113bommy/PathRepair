#include <bits/stdc++.h>
using namespace std;
int tab1[50 + 10][50 + 10];
int tab2[50 + 10][50 + 10];
int n1, m1;
int n2, m2;
int cal(int x, int y) {
  int tmp = 0;
  for (int i = 1; i <= n1; ++i)
    for (int j = 1; j <= m1; ++j) {
      if (i + x <= 0 || j + y <= 0 || i + x > n2 || j + y > m2) continue;
      tmp += tab1[i][j] * tab2[i + x][j + y];
    }
  return tmp;
}
void solve() {
  int res = -2147483647;
  pair<int, int> pos;
  for (int x = -n1; x <= n2; ++x)
    for (int y = -m1; y <= m2; ++y) {
      int tmp = cal(x, y);
      if (res < tmp) {
        res = tmp;
        pos = pair<int, int>(x, y);
      }
    }
  cout << pos.first << " " << pos.second << endl;
}
int main() {
  cin >> n1 >> m1;
  for (int i = 1; i <= n1; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < tmp.size(); ++j) tab1[i][j + 1] = tmp[j] - '0';
  }
  cin >> n2 >> m2;
  for (int i = 1; i <= n2; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < tmp.size(); ++j) tab2[i][j + 1] = tmp[j] - '0';
  }
  solve();
  return 0;
}
