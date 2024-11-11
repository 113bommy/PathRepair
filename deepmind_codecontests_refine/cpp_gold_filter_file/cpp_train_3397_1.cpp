#include <bits/stdc++.h>
using namespace std;
int n, m, x, q, ans, f1, mem[65];
vector<pair<int, int>> arr[65];
char ch;
string s;
int main() {
  memset(mem, -1, sizeof mem);
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> ch;
      arr[(ch - 'a') + 14].push_back({i, j});
    }
  }
  scanf("%d", &q);
  cin >> s;
  for (int i = 'A'; i <= 'Z'; ++i) {
    int f = 1;
    for (auto v : arr[tolower(i) - 'a' + 14]) {
      int a = v.first;
      int b = v.second;
      for (auto p : arr[('S' - 'a') + 14]) {
        if (pow((a - p.first), 2) + pow((b - p.second), 2) <= pow(x, 2)) {
          f = 0;
          break;
        }
      }
    }
    mem[tolower(i) - 'a' + 14] = f;
  }
  for (int i = 0; i < q; ++i) {
    if ((isupper(s[i]) && arr[('S' - 'a') + 14].empty()) ||
        arr[tolower(s[i]) - 'a' + 14].empty()) {
      f1 = 1;
      continue;
    }
    if (isupper(s[i])) {
      ans += mem[tolower(s[i]) - 'a' + 14];
    }
  }
  printf("%d\n", (!f1) ? ans : -1);
}
