#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int i = 0;
  while (i < n) {
    cin >> a[i];
    i++;
  }
  i = 0;
  long long int count, j, ans = 1e5;
  while (i < n) {
    j = 0;
    count = 0;
    while (j < n) {
      count += 2 * a[j] * (abs(i - j) + j + i);
      j++;
    }
    ans = min(ans, count);
    i++;
  }
  cout << ans;
}
