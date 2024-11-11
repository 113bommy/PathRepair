#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long b[N];
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      scanf("%1d", &a[i]);
    }
    a[n + 1] = -1;
    long long cnt = 1;
    long long num = 0;
    for (int i = 2; i <= n + 1; i++) {
      if (a[i] == a[i - 1])
        cnt++;
      else {
        b[++num] = cnt;
        cnt = 1;
      }
    }
    long long ans = 0;
    if (num == 1) {
      cout << 1 << endl;
      continue;
    }
    int j = 1;
    int i = 1;
    while (i <= j && i <= num) {
      if (b[i] >= 2) {
        i++;
        ans++;
      } else {
        while (j <= num) {
          if (b[i] == 1)
            j++;
          else
            break;
        }
        if (j <= num && b[j] >= 1) {
          b[j]--;
          i++;
        } else {
          i++;
          i++;
        }
        ans++;
      }
      while (j < i) j++;
    }
    cout << ans << endl;
  }
  return 0;
}
