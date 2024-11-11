#include <bits/stdc++.h>
using namespace std;
const int N = 40000 + 50;
long long n, l, s[N], c[N], num, ans;
string ss;
int a[N];
int main() {
  cin >> n >> ss;
  l = ss.size();
  for (int i = 0; i < l; i++) {
    a[i + 1] = ss[i] - '0';
  }
  for (int i = 1; i <= l; i++) {
    s[i] = s[i - 1] + a[i];
    for (int j = 0; j <= i; j++) {
      c[s[i] - s[j]]++;
      num++;
    }
  }
  if (n > 0) {
    for (int i = 1; i <= 40000; i++)
      if (n % i == 0 && n / i < 40000) ans += c[i] * c[n / i];
    cout << ans << endl;
  } else
    cout << (2 * c[0] * num) - c[0] * c[0];
  return 0;
}
