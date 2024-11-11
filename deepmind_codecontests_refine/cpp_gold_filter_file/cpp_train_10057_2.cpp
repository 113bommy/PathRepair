#include <bits/stdc++.h>
using namespace std;
long long height[105];
long long n, k;
long long ans = 1;
bool check(long long day) {
  long long num = 0;
  for (int i = 0; i < n; i++) {
    num += (height[i] + day - 1) / day;
  }
  return num <= k / day;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> height[i];
    k += height[i];
  }
  for (long long i = 1, j; i <= k; i = j + 1) {
    j = k / (k / i);
    if (check(j)) {
      ans = j;
    }
  }
  cout << ans << endl;
  return 0;
}
