#include <bits/stdc++.h>
using namespace std;
long long a[505][505];
long long b[505][505];
vector<long long> aa[1005];
vector<long long> bb[1005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &a[i][j]);
      aa[i + j].push_back(a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &b[i][j]);
      bb[i + j].push_back(b[i][j]);
    }
  }
  int flag = 1;
  for (int i = 2; i <= max(n, m) * 2; i++) {
    sort(aa[i].begin(), aa[i].end());
    sort(bb[i].begin(), bb[i].end());
    if (aa[i] != bb[i]) flag = 0;
    if (!flag) break;
  }
  if (!flag)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
