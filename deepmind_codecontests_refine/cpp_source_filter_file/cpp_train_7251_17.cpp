#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, s, a, b, x = 0, ans, arr[110];
  cin >> n >> s;
  for (i = 1; i <= n; i++) {
    cin >> a >> b;
    arr[i] = (a * 60) + b;
  }
  if (arr[1] > (s + 1)) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  s *= 2;
  s++;
  bool ok = 0;
  for (i = 1; i <= n; i++) {
    if ((arr[i] - x) > s) {
      ans = x + ((s - 1) / 2);
      ans++;
      ok = 1;
      break;
    }
    x = arr[i];
  }
  if (ok == 0) {
    ans = x + ((s - 1) / 2);
    ans++;
  }
  cout << ans / 60 << " " << ans % 60 << endl;
}
