#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T-- != 0) {
    long long n, m, x, y, sum = 0;
    long long arr[1000002];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      sum += x;
      arr[i] = x - y;
    }
    sort(arr, arr + n);
    int cnt = 0;
    while (sum > m) {
      cnt++;
      sum -= arr[n - cnt];
      if (cnt == n) {
        break;
      }
    }
    if (sum <= m)
      cout << cnt << '\n';
    else
      cout << "-1\n";
  }
}
