#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long double EPS = 1e-7;
const long double PI = acos(-1);
const int K = 524288;
int a[N];
vector<int> d[N];
int main() {
  long long n, ans = 0;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &a[i]);
    d[a[i]].push_back(i);
  }
  d[0].push_back(0);
  d[0].push_back(0);
  for (int i = 1; i <= n; i++) {
    int r1 = abs(d[i][0] - d[i - 1][0]) + abs(d[i][1] - d[i - 1][1]);
    int r2 = abs(d[i][1] - d[i - 1][0]) + abs(d[i][0] - d[i - 1][1]);
    ans += min(r1, r2);
  }
  cout << ans << endl;
}
