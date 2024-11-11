#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << 1 << " " << 0;
      return 0;
    }
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long a = arr[0], b = arr[n - 1];
    long long cnt1 = 1, cnt2 = 1;
    long long i = 0, j = n - 1;
    while (1) {
      if (a > b) {
        j--;
        if (j == i) {
          break;
        }
        b += arr[j];
        cnt2++;
      } else {
        i++;
        if (i == j) {
          break;
        }
        a += arr[i];
        cnt1++;
      }
    }
    cout << cnt1 << " " << cnt2;
    return 0;
  }
  return 0;
}
