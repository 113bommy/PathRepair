#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first || (a.first == b.first && a.second > b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int j = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a % m < j % m)
      ans += ((m - (a % m)) + (j % m));
    else
      ans += (a % m) - (j % m);
    ans += (b - a + 1);
    j = b + 1;
  }
  cout << ans << endl;
  return 0;
}
