#include <bits/stdc++.h>
using namespace std;
int n, sq = 2500;
int a[1000007], b[1000007];
vector<pair<int, int> > block[1007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    block[a[i] / sq].push_back(make_pair(b[i], i));
  }
  for (int i = 0; i <= 500; i++) {
    if (block[i].empty()) continue;
    sort(block[i].begin(), block[i].end());
    for (int j = 0; j < block[i].size(); j++) cout << block[i][j].second << " ";
  }
}
