#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int EPS = 1e-6;
long long a[MAXN], b[MAXN];
vector<int> g[MAXN], v;
bool used[MAXN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long n, m, k, cnt = 0, sum = 0, mx = 0, mn = INF;
  bool y = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cnt += (1 << i);
  }
  cout << cnt;
  return 0;
}
