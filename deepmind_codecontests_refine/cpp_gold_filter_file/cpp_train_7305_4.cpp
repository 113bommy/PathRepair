#include <bits/stdc++.h>
using namespace std;
long long arr[223456];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, c = 0, t, ans;
  cin >> t;
  string s;
  while (t--) {
    c = 0;
    ans = 0;
    cin >> n >> a >> b;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      arr[i] = s[i] - '0';
      if (arr[i]) c++;
    }
    long long i = 0;
    if (c == 0) {
      cout << a * n + b * (n + 1) << "\n";
      continue;
    }
    for (i; i < n; i++) {
      if (arr[i] == 1) {
        c--;
        break;
      }
    }
    ans = ans + (i + 1) * a + (i)*b;
    long long prev;
    while (c) {
      prev = i;
      i++;
      while (arr[i] == 1) {
        i++;
        c--;
      }
      ans = ans + (i - prev) * a + (i - prev) * 2 * b;
      if (c == 0) {
        ans = ans - a - 2 * b;
        i--;
        break;
      }
      prev = i - 1;
      while (arr[i] == 0) {
        i++;
      }
      c--;
      if (((i - prev - 2) * b - 2 * a > 0) && (i - prev > 2)) {
        ans = ans + (i - prev) * b + (i - prev - 1 + 2) * a;
      } else {
        ans = ans + (i - prev - 1) * a + (i - prev - 1) * 2 * b;
      }
    }
    ans = ans + (n + 3 - i) * b + (n - i + 1) * a;
    i = n + 1;
    cout << ans << "\n";
  }
  return 0;
}
