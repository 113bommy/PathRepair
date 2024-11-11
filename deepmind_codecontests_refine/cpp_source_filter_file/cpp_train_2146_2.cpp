#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  long long count = 1;
  long long ans = 0;
  long long flag = 0;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      count += 1;
      flag = 1;
    } else {
      ans += (count * (count - 1)) / 2;
      flag = 0;
      count = 1;
    }
  }
  if (flag == 1) ans += (count * (count + 1)) / 2;
  cout << ans + n << "\n";
}
