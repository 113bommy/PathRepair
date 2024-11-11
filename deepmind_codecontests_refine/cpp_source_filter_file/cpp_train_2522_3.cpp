#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
long long c[N];
long long d[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c[i] = x;
  }
  cnt = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    d[i] = x;
  }
  long long arr = 0;
  for (long long i = 1; i <= sqrt(k); i++) {
    long long cnt1 = 0, cnt2 = 0;
    cnt = 0;
    if (k % i == 0) {
      for (int j = 0; j < n; j++) {
        if (c[j] == 1)
          cnt++;
        else
          cnt = 0;
        if (cnt >= i) cnt1++;
      }
      cnt = 0;
      for (int j = 0; j < m; j++) {
        if (d[j] == 1)
          cnt++;
        else
          cnt = 0;
        if (cnt >= k / i) cnt2++;
      }
      arr += cnt1 * cnt2;
      cnt1 = cnt2 = cnt = 0;
      if (i != k / i) {
        for (int j = 0; j < n; j++) {
          if (d[j] == 1)
            cnt++;
          else
            cnt = 0;
          if (cnt >= i) cnt1++;
        }
        cnt = 0;
        for (int j = 0; j < m; j++) {
          if (c[j] == 1)
            cnt++;
          else
            cnt = 0;
          if (cnt >= k / i) cnt2++;
        }
        arr += cnt1 * cnt2;
      }
    }
  }
  cout << arr;
}
