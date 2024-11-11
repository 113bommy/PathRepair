#include <bits/stdc++.h>
using namespace std;
long long mx = -1e9, mn = 1e9 + 5;
long long T, n, m, k, ans, a[100005], b, c, d, l, r, sum, mid, coin, cnt, pos,
    number, x, y, z;
long long dp[300005];
vector<string> v, v1;
map<string, long long> mp, mm;
map<long long, long long>::iterator it;
pair<long long, long long> p[5000];
queue<long long> q;
priority_queue<long long> pq;
string s;
int main() {
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }
  ans = 1;
  for (int i = 2; i <= n; i++) {
    ans *= 3;
    ans %= 1000003;
  }
  cout << ans;
}
