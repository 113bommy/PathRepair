#include <bits/stdc++.h>
using namespace std;
long long a[100001];
long long b[100001];
long long maxn = -1e18;
long long minn = 1e18;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  cout << max((n + m) / 3, max(n, m));
}
