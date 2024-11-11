#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    int free[210]{0};
    int a[105], b[105];
    long long int l = 2 * n;
    for (int i = 0; i < k; i++) {
      l -= 2;
      cin >> a[i] >> b[i];
      free[a[i]]++;
      free[b[i]]++;
    }
    long long int ans = ((n - k) * (n - k - 1)) / 2;
    for (int i = 0; i < k; i++) {
      int x = a[i];
      int y = b[i];
      if (x > y) swap(x, y);
      long long int cnt = 0;
      for (int j = x + 1; j < y; j++) {
        if (!free[j]) cnt++;
      }
      ans += min(cnt, l - cnt);
      for (int j = i + 1; j < k; j++) {
        int u = a[j];
        int v = b[j];
        if ((x < u && u < y) ^ (x < v && v < y)) ans++;
      }
    }
    cout << ans << endl;
  }
}
