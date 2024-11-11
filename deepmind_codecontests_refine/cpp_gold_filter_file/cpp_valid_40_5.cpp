#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 10;
int arr[MAX], arr2[MAX];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int second = 0, x = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      second += arr[i];
    }
    arr2[0] = 0;
    for (int i = 1; i < n + 1; ++i) cin >> arr2[i];
    int ans = second;
    for (int i = 0; i < n; ++i) {
      second -= arr[i];
      x += arr2[i];
      ans = min(ans, max(second, x));
    }
    cout << ans << '\n';
  }
  exit(0);
}
