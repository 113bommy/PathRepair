#include <bits/stdc++.h>
using namespace std;
long long n, k, a[100100], sum = 0, s[101000], ans, num;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) s[i] = n + 1;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    num = upper_bound(s, s + n, a[i]) - s;
    s[num] = a[i];
  }
  for (long long i = 0; i < n; i++) {
    if (s[i] == n + 1) {
      ans = i;
      break;
    }
  }
  cout << ans;
}
