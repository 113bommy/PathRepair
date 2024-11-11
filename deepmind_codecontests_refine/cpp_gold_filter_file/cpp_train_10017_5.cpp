#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n], count = 0, an;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 != 0) count++;
  }
  if (count == 1) {
    cout << 1;
    return 0;
  }
  if (count == n) {
    if (n % 2 == 0) {
      cout << 0;
      return 0;
    } else {
      cout << n;
      return 0;
    }
  }
  if (count % 2 != 0)
    cout << count;
  else
    cout << n - count;
}
