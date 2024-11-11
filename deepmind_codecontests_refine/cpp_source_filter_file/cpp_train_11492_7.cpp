#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int knightDir[8][2] = {{-2, -1}, {-2, 1}, {-1, 2},  {1, 2},
                             {2, -1},  {2, 1},  {-1, -2}, {1, -2}};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const long long MOD = 1000000000 + 7;
int par[105], has[105];
int n, m;
int find(int x) {
  if (par[x] == x)
    return x;
  else
    par[x] = find(par[x]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    cin >> n >> m;
    int c = 0;
    for (int i = 1; i <= m; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      if (k == 0)
        c++;
      else {
        int a;
        cin >> a;
        has[a] = 1;
        for (int i = 1; i < k; i++) {
          int b;
          cin >> b;
          has[b] = 1;
          par[find(a)] = find(b);
        }
      }
    }
    set<int> s;
    for (int i = 1; i <= m; i++) {
      if (has[i]) s.insert(find(i));
    }
    int cnt = s.size();
    if (cnt == 0) cnt++;
    cout << cnt + c - 1 << endl;
  }
}
