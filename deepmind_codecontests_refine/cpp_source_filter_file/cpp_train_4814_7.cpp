#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    long long a[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long long temp = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[n - i];
      cnt++;
      long long h = x * i;
      if (sum < h) {
        cnt--;
        break;
      }
      temp = i;
    }
    cout << cnt << endl;
  }
}
