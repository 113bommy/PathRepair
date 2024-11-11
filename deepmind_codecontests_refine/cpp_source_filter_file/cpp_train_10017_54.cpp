#include <bits/stdc++.h>
using namespace std;
int a[200];
int main() {
  long long sum, ans = 0, n;
  cin >> n;
  sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum = +a[i];
  }
  for (long long i = 0; i < n; i++)
    if (sum - a[i] % 2 == 0) {
      ans++;
    }
  cout << ans << endl;
  return 0;
}
