#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main() {
  for (int i = 2; i <= 35; i++) {
    a[i] = a[i - 1] * 2 + 1;
  }
  for (int i = 2; i <= 35; i++) {
    a[i] = a[i] * (a[i] / 2 + 1);
  }
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sum = 0;
    int ans = 0;
    int i = 1;
    while (sum < n) {
      sum += a[i++];
      if (sum <= n) ans++;
    }
    cout << ans << endl;
  }
}
