#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<long long int, long long int> > vp;
map<long long int, long long int> mp, mpp;
vector<long long int> v, v1, v2;
long long int dp[N], visit[N];
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << "  ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, val, k, d, mi = 1e9, mx(0);
  long long int sum(0), ct(0), p(0), q(0);
  cin >> n >> m;
  if (n <= 2 * m)
    cout << 0 << ' ';
  else
    cout << n - 2 * m << ' ';
  long long int low = 1, high = n;
  while (low <= high) {
    long long int mid = (low + high) >> 1;
    if (((mid * (mid - 1) / 2)) >= m) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << n - (high + 1);
}
