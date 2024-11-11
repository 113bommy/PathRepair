#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, int> mp1, mp2;
  for (int i = 1; i <= max(n, m); i++) {
    if (i <= n) {
      mp1[i % 5]++;
    }
    if (i <= m) {
      mp2[i % 5]++;
    }
  }
  long long ans = 0;
  for (auto a : mp1) {
    int rem = 5 - a.first;
    if (rem == 0 || a.first == 0) {
      ans += (mp1[0] * mp2[0]);
      continue;
    }
    ans += (a.second * mp2[rem]);
  }
  cout << ans << "\n";
}
