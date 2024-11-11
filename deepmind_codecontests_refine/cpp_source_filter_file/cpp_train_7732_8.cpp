#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int sum = 350, count = 0;
  int ans = 0;
  int j;
  for (int i = 0; i < n; i++) {
    if (sum - a[i] >= 0) {
      sum -= a[i];
      ans++;
    } else {
      if (a[i] < sum + 360) {
        ans++;
        count = a[i] - sum;
      }
      j = i + 1;
      break;
    }
  }
  int x = count;
  int x1 = count;
  for (; j < n; j++) {
    if (x1 + a[j] <= 360) {
      ans++;
      count += a[j] + x;
      x1 += a[j];
      x += a[j];
    } else {
      break;
    }
  }
  cout << ans << " " << count << endl;
}
