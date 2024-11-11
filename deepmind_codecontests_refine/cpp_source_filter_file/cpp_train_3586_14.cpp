#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  long long low = 1, high = n * m, ans = -1;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long cnt = 0, equal = 0;
    for (int i = 1; i <= n; i++) {
      long long val = min(m, mid / i);
      if (val * i == mid) {
        equal++;
      }
      cnt += val;
    }
    if (cnt < k - 1) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << low;
}
