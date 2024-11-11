#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  map<int, int> mp;
  int n, m, a;
  cin >> n;
  long long n1 = n;
  while (n--) {
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> a;
      mp[a]++;
    }
  }
  for (auto it : mp) {
    if (it.second == n1) cout << it.first;
  }
  return 0;
}
