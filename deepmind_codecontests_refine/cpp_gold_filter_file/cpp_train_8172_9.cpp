#include <bits/stdc++.h>
using namespace std;
const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int NEG_INF = -1000000000;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int main() {
  int grid[1001][1001];
  int n, a, b;
  cin >> n;
  map<pair<int, int>, int> cnt;
  while (n--) {
    cin >> a >> b;
    cnt[pair<int, int>(b + a, -1)]++;
    cnt[pair<int, int>(a - b, 1)]++;
  }
  long long ans = 0;
  for (map<pair<int, int>, int>::iterator it = cnt.begin(); it != cnt.end();
       it++) {
    ans += it->second * (it->second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
