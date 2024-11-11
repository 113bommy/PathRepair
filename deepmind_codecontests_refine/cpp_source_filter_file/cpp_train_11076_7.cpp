#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[1000000];
  cin >> a;
  if (strlen(a) < 5) {
    cout << 0 << endl;
    return (0);
  }
  long i, j = 0, l, ans = 0;
  for (i = 0; i < strlen(a) - 4; i++) {
    if (a[i] == 'h' && a[i + 1] == 'e' && a[i + 2] == 'a' && a[i + 3] == 'v' &&
        a[i + 4] == 'y')
      j++;
    if (a[i] == 'm' && a[i + 1] == 'e' && a[i + 2] == 't' && a[i + 3] == 'a' &&
        a[i + 4] == 'l')
      ans += j;
  }
  cout << ans << endl;
  return (0);
}
