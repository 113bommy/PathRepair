#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, tmp, flag = 0;
    cin >> n;
    vector<int> minI(n, n), maxI(n, -1);
    for (int i = 0; i < n && cin >> tmp; i++)
      minI[tmp] = min(minI[tmp], i), maxI[tmp] = max(maxI[tmp], i);
    for (int i = 1; i < n; i++) flag |= (maxI[i] - minI[i]) > 1;
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
