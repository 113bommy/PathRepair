#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int nax = 1e5 + 10;
vector<int> tree(4 * nax);
long long i, j, x, y, k;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, cnt = 0;
  cin >> n;
  vector<vector<long long>> a(n + 1);
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    if (a[i].size() == 1) cnt++;
  }
  cout << cnt << endl;
}
