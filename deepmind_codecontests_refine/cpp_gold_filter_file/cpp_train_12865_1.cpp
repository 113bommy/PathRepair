#include <bits/stdc++.h>
using namespace std;
vector<int> v[101000];
vector<int> f[101010];
int ma[100006];
int main() {
  int n, m;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    v[0].push_back(0);
    f[0].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (x >= v[i - 1][j])
        f[i].push_back(f[i - 1][j]);
      else
        f[i].push_back(i);
      v[i].push_back(x);
    }
  }
  int k;
  cin >> k;
  for (int i = 1; i <= n; i++) {
    ma[i] = 2 * 1e9;
    for (int j = 0; j < m; j++) {
      ma[i] = min(ma[i], f[i][j]);
    }
  }
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    int ff = 0;
    for (int j = 0; j < m; j++) {
      if (ma[r] <= l) {
        ff = 1;
        printf("Yes\n");
        break;
      }
    }
    if (!ff) printf("No\n");
  }
}
