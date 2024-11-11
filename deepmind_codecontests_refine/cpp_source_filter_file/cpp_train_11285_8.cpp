#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, MOD = 1e9 + 7;
vector<int> d[32];
int a[100000], n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j < 31; j++)
      if (a[i] & (1 << j)) d[j].push_back(a[i]);
  }
  int beauty = -1;
  for (int i = 0; i < 31; i++) {
    if (d[i].empty()) continue;
    int k = d[i][0];
    for (int j = 0; j < d[i].size(); j++) k &= d[i][j];
    if (k == (1 << i)) beauty = i;
  }
  if (beauty == -1) {
    cout << n << endl;
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
  } else {
    cout << d[beauty].size() << endl;
    for (int i = 0; i < d[beauty].size(); i++) printf("%d ", d[beauty][i]);
  }
}
