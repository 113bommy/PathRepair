#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int oo = 1e9;
int n;
int a[105];
int sum;
int ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sort(a, a + n);
  if ((double)sum / (double)n >= 4.5) return cout << 0, 0;
  for (int i = 0; i < n; i++) {
    double x = sum - a[i] + 5;
    if ((x / (double)n) >= 4.5) {
      ans++;
      break;
    } else {
      ans++;
      sum -= a[i];
      sum += 5;
    }
  }
  cout << ans;
  return 0;
}
