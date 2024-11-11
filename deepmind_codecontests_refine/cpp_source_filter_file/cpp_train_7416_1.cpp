#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a[50000] = {0};
  a[0] = 2;
  for (long long int i = 1; i < 50000; i++) a[i] = a[i - 1] + 3;
  for (long long int i = 1; i < 50000; i++) a[i] += a[i - 1];
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    int count = 0;
    int i = 49999;
    while (n >= 2 and i >= 0) {
      if (a[i] <= n) {
        count += 1;
        n -= a[i];
        i--;
      } else if (a[i] > n) {
        i--;
        continue;
      }
    }
    cout << count << endl;
  }
  return 0;
}
