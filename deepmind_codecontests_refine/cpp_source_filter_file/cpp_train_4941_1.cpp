#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 2e9 + 5;
double PI = 3.14159265358979323846;
long long int cardsRequired(long long int floors) {
  return 3 * floors * (floors + 1) / 2 - floors;
}
long long int getMaxHeight(long long int n) {
  long long int ans = 0;
  long long int s = 0;
  long long int e = 1e8;
  while (s <= e) {
    long long int m = (s + e) >> 1;
    if (cardsRequired(m) <= n) {
      ans = s;
      s = m + 1;
    } else {
      e = m - 1;
    }
  }
  return ans;
}
void solve() {
  long long int n;
  cin >> n;
  long long int maxheightPossible = getMaxHeight(n);
  while ((maxheightPossible + n) % 3) {
    maxheightPossible--;
  }
  long long int ans = (maxheightPossible + 3 - 1) / 3;
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
