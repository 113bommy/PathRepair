#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
int cnt, num[60010];
int main() {
  cin >> n;
  long long k = (1ll * n * (n + 1) / 2);
  if (k & 1) {
    cout << 1 << endl;
    sum = k / 2 + 1;
  } else {
    cout << 0 << endl;
    sum = k / 2;
  }
  for (int i = n; i >= 1; i--) {
    if (sum - i > 0) {
      sum -= i;
      num[++cnt] = i;
    } else if (sum == i) {
      sum -= i;
      num[++cnt] = i;
      break;
    }
  }
  cout << cnt << ' ';
  for (int i = 1; i <= cnt; i++) cout << num[i] << ' ';
  cout << endl;
  return 0;
}
