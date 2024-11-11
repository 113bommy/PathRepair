#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, x, s = 0;
    cin >> n >> x;
    long long a[n], cnt[1001] = {0};
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i] - 1]++;
    }
    for (long long i = 0; i < 101; i++) {
      if (cnt[i] == 0) x--;
      if (x == 0) {
        for (long long j = i + 1; j < 102; j++) {
          if (cnt[j] == 0) {
            s = j;
            break;
          }
        }
        break;
      }
    }
    cout << s;
    cout << '\n';
  }
  return 0;
}
