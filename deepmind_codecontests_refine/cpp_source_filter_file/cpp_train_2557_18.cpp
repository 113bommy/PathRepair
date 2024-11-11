#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int n, m, k;
vector<int> v[1111111];
int cc;
bool u[1111111];
void dfs(int ver) {
  if (u[ver]) return;
  u[ver] = true;
  cc++;
  for (int i(0); i < (v[ver].size()); ++i) dfs(v[ver][i]);
}
int main() {
  cin >> n >> m >> k;
  for (int i(0); i < (m); ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  vector<int> c;
  for (int i(0); i < (n); ++i)
    if (!u[i]) {
      cc = 0;
      dfs(i);
      c.push_back(cc);
    }
  sort((c).begin(), (c).end());
  if (k == 1) {
    cout << max(0, (int)c.size() - 2) << endl;
  } else {
    int num1 = 0;
    for (int i(0); i < (c.size()); ++i)
      if (c[i] == 1) num1++;
    int num2 = 0;
    for (int i(0); i < (c.size()); ++i)
      if (c[i] > 2) num2 += min(k - 2, c[i] - 2);
    num1 -= num2;
    cout << (num1 - 1) / 2 << endl;
  }
  return 0;
}
