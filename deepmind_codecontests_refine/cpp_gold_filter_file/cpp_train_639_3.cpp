#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
long long a[maxn];
long long n, m, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  long long page = k, begin = 1, square = 0, ans = 0;
  while (square < m) {
    if (page + square >= a[begin]) {
      long long cnt = 0;
      while (begin <= m && page + square >= a[begin]) {
        begin++;
        cnt++;
      }
      square += cnt;
      ans++;
    } else {
      page = (a[begin] - square + k - 1) / k * k;
    }
  }
  cout << ans << endl;
  return 0;
}
