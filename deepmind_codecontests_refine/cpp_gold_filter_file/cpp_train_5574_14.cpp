#include <bits/stdc++.h>
using namespace std;
int n, m, rs;
void swap(int& u, int& v) {
  int temp = u;
  u = v;
  v = temp;
}
int main() {
  cin >> n >> m;
  int bot = 1, top = n;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    if (u > v) swap(u, v);
    bot = max(bot, u);
    top = min(top, v);
  }
  cout << max(0, top - bot);
  return 0;
}
