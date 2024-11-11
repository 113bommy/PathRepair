#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const long long mod = 1000000007;
const int INF = INT_MAX;
long long x, y;
vector<long long> vec;
int dp[100];
void init() {
  for (int pos = 0; pos < 80; pos++) dp[pos] = 1;
  for (int i = 2; i <= 61; i++) {
    long long tmp = (1LL << (long long)i) - 1;
    for (int j = 0; j < i - 1; j++) {
      vec.push_back(tmp ^ (1LL << (long long)j));
    }
  }
}
int main() {
  init();
  sort(vec.begin(), vec.end());
  cin >> x >> y;
  int pos1 = lower_bound(vec.begin(), vec.end(), x - 1) - vec.begin();
  int pos2 = lower_bound(vec.begin(), vec.end(), y) - vec.begin();
  int ans = pos2 - pos1;
  cout << ans << endl;
  return 0;
}
