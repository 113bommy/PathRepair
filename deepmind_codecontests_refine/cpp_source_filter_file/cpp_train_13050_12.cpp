#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const long long LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;
struct swop {
  int x;
  int y;
  int p;
  int q;
};
int n;
int c[N];
int a[100][100];
int gab[100][100];
pair<int, int> pos[N];
vector<swop> ans;
int main() {
  swop op;
  pair<int, int> want;
  cin >> n;
  int id = 1;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < c[i]; j++) {
      gab[i][j] = id;
      id++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i]; j++) {
      int u;
      cin >> u;
      a[i][j] = u;
      pos[u].first = i;
      pos[u].second = j;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i]; j++) {
      int g = gab[i][j];
      int u = a[i][j];
      if (g != u) {
        want = pos[g];
        op.x = j;
        op.y = i;
        op.p = want.second;
        op.q = want.first;
        ans.push_back(op);
        a[i][j] = g;
        a[want.first][want.second] = u;
        pos[u] = want;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto opp : ans) {
    cout << opp.x + 1 << " " << opp.y + 1 << " " << opp.p + 1 << " "
         << opp.q + 1 << "\n";
  }
  return 0;
}
