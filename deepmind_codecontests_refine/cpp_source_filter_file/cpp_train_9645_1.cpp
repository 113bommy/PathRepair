#include <bits/stdc++.h>
using namespace std;
const int dzs = 500017;
vector<int> _map[500017];
int n;
int ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t;
    bool f = 1;
    scanf("%d", &t);
    int tmp = t % dzs;
    for (int j = 0; j < _map[tmp].size(); j++)
      if (_map[tmp][j] == t) {
        f = 0;
        break;
      }
    if (f) _map[tmp].push_back(t), ans++;
  }
  printf("%d", ans);
  return 0;
}
