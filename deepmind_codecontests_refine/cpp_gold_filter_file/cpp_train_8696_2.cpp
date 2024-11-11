#include <bits/stdc++.h>
using namespace std;
int a[(int)1e5 + 5];
vector<pair<int, int> > v[(int)1e5 + 5];
long long sum = 0;
int ct;
void dfs(int d, int par, bool mark) {
  if (sum > a[d] && d != 0 || mark) {
    mark = true;
    ct++;
  }
  for (int i = 0; i < (int)v[d].size(); i++) {
    if (v[d][i].first != par) {
      long long temp = sum;
      sum = max(sum + 1LL * v[d][i].second, 1LL * v[d][i].second);
      dfs(v[d][i].first, d, mark);
      sum = temp;
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int x, y;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    v[x - 1].push_back(make_pair(i + 1, y));
  }
  dfs(0, -1, false);
  cout << ct << endl;
}
