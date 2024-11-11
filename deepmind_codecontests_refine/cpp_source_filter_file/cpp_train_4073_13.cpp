#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, k, a[2 * N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int left = 1, right = n + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    int m_cnt = m, sum = 2e9;
    bool flag = true;
    for (int i = n - mid + 1; i <= n; i++) {
      if (sum + a[i] > k) {
        if (m_cnt == 0) {
          flag = false;
          break;
        }
        sum = a[i];
        m_cnt--;
      } else {
        sum = sum + a[i];
      }
    }
    if (flag == true) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left;
}
