#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, tc;
  cin >> tc;
  for (t = 1; t <= tc; t++) {
    long long a, b, p, sum = 0, lagbe, n, i, flag;
    string s;
    char cur;
    cin >> a >> b >> p;
    cin >> s;
    n = s.size();
    long long arr[n + 2];
    memset(arr, 0, sizeof(arr));
    cur = s[0];
    for (i = 1; i < n; i++) {
      if (s[i] == cur)
        continue;
      else if (s[i] != cur) {
        if (cur == 'A') {
          cur = s[i];
          sum += a;
          arr[i] = sum;
        } else {
          cur = s[i];
          sum += b;
          arr[i] = sum;
        }
      }
    }
    if (s[n - 1] == s[n - 2]) {
      if (s[n - 1] == 'A') {
        sum += a;
        arr[n - 1] = sum;
      } else {
        sum += b;
        arr[n - 1] = sum;
      }
    }
    flag = 0;
    for (i = 0; i < n; i++) {
      lagbe = sum - arr[i];
      if (lagbe <= p) break;
    }
    if (p >= sum)
      cout << 1 << endl;
    else
      cout << i + 1 << endl;
  }
  return 0;
}
