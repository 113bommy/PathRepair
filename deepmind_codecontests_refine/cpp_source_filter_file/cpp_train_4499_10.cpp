#include <bits/stdc++.h>
using namespace std;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const long double PI = 3.141592653589793;
const long long INF = 9223372036854775807ll;
const long long mod = 1e9 + 7;
void solve() {
  vector<long long> nums;
  long long prev = 1, cur = 2;
  nums.push_back(1);
  while (cur < 1e18) {
    nums.push_back(cur);
    long long temp = prev;
    prev = cur;
    cur += temp;
  }
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> indices;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (n >= nums[i]) {
        n -= nums[i];
        indices.push_back(i + 1);
      }
    }
    indices.push_back(0);
    reverse(indices.begin(), indices.end());
    long long ways[indices.size()][2];
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;
    for (int i = 1; i < indices.size(); ++i) {
      ways[i][0] = ways[i - 1][0] + ways[i - 1][1];
      ways[i][1] = ways[i - 1][0] * (indices[i] - indices[i - 1] - 1) / 2 +
                   ways[i - 1][1] * (indices[i] - indices[i - 1]) / 2;
    }
    cout << ways[indices.size() - 1][0] + ways[indices.size() - 1][1] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  solve();
  return 0;
}
