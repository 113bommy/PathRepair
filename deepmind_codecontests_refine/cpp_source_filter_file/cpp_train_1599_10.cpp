#include <bits/stdc++.h>
using namespace std;
long long a, b, c[1234567], dp[4005][4005], d[1234567], e, n, j, i, l, r, x, y,
    k, ans, sz;
bool used[52345670];
long long T;
char ch[1234][1234];
vector<long long> v[1234567], v1, vv;
string s, s1[1234567];
priority_queue<long long> pq;
long long sum;
map<long long, long long> ma, m;
long long ar[1234567];
long long mod = 998244353;
long long fac[1234567];
set<long long> se;
int main() {
  cin >> n;
  x = 0;
  y = 1;
  for (long long i = 1; i <= n; i++) {
    ans += (x + y);
    if (i % 2 == 0)
      y += x;
    else
      x += y;
    ans %= 1000000009;
    x %= 1000000009;
    y %= 1000000009;
  }
  cout << ans;
}
