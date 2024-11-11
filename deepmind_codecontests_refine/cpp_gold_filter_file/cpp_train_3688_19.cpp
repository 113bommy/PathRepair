#include <bits/stdc++.h>
using namespace std;
int arr[1009];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ar[n];
  for (int i = 1; i <= n - 1; i++) {
    cin >> ar[i];
  }
  int a, b, ans = 0;
  cin >> a >> b;
  for (int i = a; i < a + b - a; i++) {
    ans += ar[i];
  }
  cout << ans << "\n";
  return 0;
}
