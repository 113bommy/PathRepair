#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
long long a[100], s[100];
long long n, m, t, mi = 123456789, ans;
int main() {
  cin >> t;
  while (t--) {
    ans = 0;
    scanf("%I64d%I64d", &n, &m);
    long long sum = n / m;
    int i;
    for (i = 1; i <= sum; i++) {
      a[i] = (a[i - 1] + m) % 10;
      s[i] = s[i - 1] + a[i];
      if (i > 1 && a[i] == a[1]) break;
    }
    i--;
    if (i == 0) {
      cout << "0" << endl;
      continue;
    }
    cout << s[i - 1] * (sum / i) + s[sum % i] << endl;
  }
}
