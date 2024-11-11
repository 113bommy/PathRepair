#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long d[maxn];
    memset(d, 0, sizeof(d));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);
    int flag = 0;
    for (int i = 0; i < n / 2; i++)
      if (d[i] * d[n - 1 - i] != d[i + 1] * d[n - 2 - i]) flag = 1;
    if (flag)
      cout << -1 << endl;
    else {
      long long num = d[0] * d[n - 1], cnt = 0;
      for (long long i = 2; i <= sqrt(num); i++) {
        if (!num % i) {
          cnt++;
          if (i * i != num) cnt++;
        }
      }
      if (n == cnt)
        cout << num << endl;
      else
        cout << -1 << endl;
    }
  }
  return 0;
}
