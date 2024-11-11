#include <bits/stdc++.h>
using namespace std;
bool isprime(long long int n) {
  if (n == 1) return true;
  long long int i = 2;
  while (i * i <= n) {
    if (n % i == 0) return false;
    i += 1;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i + 1];
    sort(a + 1, a + n + 1);
    int sum = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= i) sum = i + 1;
    }
    cout << sum << endl;
  }
  return 0;
}
