#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<pair<long long int, long long int> > a[1005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long int x, y;
    cin >> x >> y;
    a[x / 1000].push_back(make_pair(y, i));
  }
  for (int i = 0; i <= 1000; i++) sort(a[i].begin(), a[i].end());
  long long int in = 0;
  for (int i = 0; i <= 1000; i++) {
    if (in % 2) reverse(a[i].begin(), a[i].end());
    for (auto j : a[i]) cout << j.second << " ";
    if (a[i].size()) in++;
  }
  cout << '\n';
  return 0;
}
