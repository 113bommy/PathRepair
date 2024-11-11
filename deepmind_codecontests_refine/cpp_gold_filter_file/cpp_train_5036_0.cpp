#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9 + 5;
const long long LINF = (long long)4E18 + 5;
const long double PI = acos(-1.0);
const long double E = 2.718281828459045L;
const double EPS = 1.0e-9;
typedef struct A {
  int to, weg, i, dir;
} edge;
vector<edge> e[200514];
int sum[200154] = {}, n;
int check[210000] = {}, ans[210000] = {};
void dfs(int from) {
  check[from] = 1;
  for (int j = 0; j < e[from].size(); j++) {
    int TO = e[from][j].to, W = e[from][j].weg, num = e[from][j].i,
        D = e[from][j].dir;
    if (ans[num] != -1) continue;
    sum[TO] -= 2 * (W);
    ans[num] = D;
  }
  for (int j = 0; j < e[from].size(); j++) {
    int TO = e[from][j].to;
    if (TO == n || check[TO])
      continue;
    else if (sum[TO] == 0) {
      dfs(TO);
    }
  }
}
int main() {
  int m, a1, b1, c1;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a1 >> b1 >> c1;
    e[a1].push_back((edge){b1, c1, i, 0});
    e[b1].push_back((edge){a1, c1, i, 1});
    sum[a1] += c1;
    sum[b1] += c1;
    ans[i] = -1;
  }
  dfs(1);
  for (int i = 0; i < m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
