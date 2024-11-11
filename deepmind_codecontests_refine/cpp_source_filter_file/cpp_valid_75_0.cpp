#include <bits/stdc++.h>
using namespace std;
void speed() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int msb(long long int n) {
  long long int t = -1;
  while (n) {
    n = n >> 1;
    ++t;
  }
  return t;
}
bool isPrime(long long int n) {
  for (long long int i = 2; i * i < n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
const long long int mod = 1e9 + 7;
long long int mypow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    b /= 2;
    a = (ans * a) % mod;
  }
  return ans;
}
class comp {
 public:
  bool operator()(const pair<long long int, long long int>& p1,
                  const pair<long long int, long long int>& p2) {
    return p1.second <= p2.second;
  }
};
bool isValid(vector<pair<long long int, long long int>>& intervals,
             long long int start) {
  for (long long int i = 0; i < intervals.size(); ++i) {
    if (start < intervals[i].first) {
      return false;
    }
    start += intervals[i].second;
  }
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int>> grid(n);
  for (long long int i = 0; i < n; ++i) {
    long long int x;
    cin >> x;
    for (long long int j = 0; j < x; ++j) {
      long long int t;
      cin >> t;
      grid[i].push_back(t);
    }
  }
  vector<pair<long long int, long long int>> intervals;
  for (long long int i = 0; i < n; ++i) {
    long long int maxNum = INT_MIN;
    long long int ind;
    for (long long int j = 0; j < grid[i].size(); ++j)
      maxNum = max(maxNum, grid[i][j] - j + 1);
    intervals.push_back({maxNum, grid[i].size()});
  }
  sort(intervals.begin(), intervals.end());
  long long int ans;
  long long int left = 0, right = 1e9;
  while (left <= right) {
    long long int mid = left + (right - left) / 2;
    if (isValid(intervals, mid)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans;
}
int main() {
  speed();
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
};
