#include <bits/stdc++.h>
using namespace std;
long long int dif(long long int a, long long int b) {
  return ((a / b) + (a % b != 0));
}
long long int p[10000001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, ans = 0;
  cin >> n;
  long long int a[n];
  long long int s = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i] > s) {
      s += a[i];
      ans++;
    }
  }
  cout << ans;
  return 0;
}
