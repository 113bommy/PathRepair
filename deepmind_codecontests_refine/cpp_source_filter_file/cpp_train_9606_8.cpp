#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 10;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;
int arr[50];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    fill(arr, arr + 50, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      arr[__builtin_clz(a)]++;
    }
    long long ans = 0;
    for (int i = 0; i < 50; i++) ans += arr[i] * (arr[i] - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}
