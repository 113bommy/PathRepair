#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    int num[n + 1];
    memset(num, 0, sizeof(num));
    num[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (arr[i] > arr[1]) {
        num[i] = 2;
      } else {
        num[i] = 1;
      }
    }
    for (int i = 2; i <= n / 2; i++) {
      for (int j = 2 * i; j <= n; j += i) {
        if (arr[j] > arr[i]) {
          num[j] = max(num[j], num[i] + 1);
        }
      }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      if (num[i] > mx) {
        mx = num[i];
      }
    }
    cout << mx << endl;
  }
}
