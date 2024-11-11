#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int cache[3001];
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j < i; ++j) {
      if (i % j == 0 && cache[j] == 0) {
        cache[i]++;
      }
    }
    if (cache[i] == 2) ans++;
  }
  cout << ans;
  return 0;
}
