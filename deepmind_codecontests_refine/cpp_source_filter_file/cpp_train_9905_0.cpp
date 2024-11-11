#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> data[2][2];
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) data[a[i] - '0'][b[i] - '0'].push_back(i);
  for (int b = 0; b <= (int)data[0][1].size(); b++) {
    for (int c = 0; c <= (int)data[1][0].size(); c++) {
      int d = data[0][1].size() + data[1][1].size() - b - c;
      if (d > (int)data[1][1].size() || d < 0 || abs(d) % 2) continue;
      d /= 2;
      int a = n / 2 - b - c - d;
      if (a < 0 || a > (int)data[0][0].size()) continue;
      for (int i = 0; i < a; i++) cout << data[0][0][i] + 1 << ' ';
      for (int i = 0; i < b; i++) cout << data[0][1][i] + 1 << ' ';
      for (int i = 0; i < c; i++) cout << data[1][0][i] + 1 << ' ';
      for (int i = 0; i < d; i++) cout << data[1][1][i] + 1 << ' ';
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
