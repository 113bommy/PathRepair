#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a[3], b[3], n, s1 = 0, s2 = 0, i;
  for (i = 0; i < 3; i++) {
    cin >> a[i];
    s1 += a[i];
  }
  for (i = 0; i < 3; i++) {
    cin >> b[i];
    s2 += b[i];
  }
  cin >> n;
  if (s1 + s2 >= n) {
    if (s1 % 5 != 0)
      s1 = (s1 / 5) + 1;
    else
      s1 /= 5;
    if (s2 % 10 != 0)
      s2 = (s2 / 10) + 1;
    else
      s2 /= 10;
    if (s1 + s2 <= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  } else if (s1 + s2 == 0)
    cout << "YES\n";
  else
    cout << "YES\n";
  return 0;
}
