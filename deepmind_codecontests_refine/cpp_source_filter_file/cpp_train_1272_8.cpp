#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], sum1[100005], sum2[100005];
int main() {
  cin >> n;
  for (register long long i = 1; i <= n; i++) cin >> a[i];
  for (register long long i = 1; i <= n; i++) sum1[i] = sum1[i - 1] | a[i];
  for (register long long i = n; i >= 1; i--) sum2[i] = sum2[i + 1] | a[i];
  long long maxx = -2147483647, pos;
  for (register long long i = 1; i <= n; i++) {
    if (maxx < sum1[n] - sum1[i - 1] | sum2[i + 1]) {
      maxx = sum1[n] - sum1[i - 1] | sum2[i + 1];
      pos = i;
    }
  }
  swap(a[pos], a[1]);
  for (register long long i = 1; i <= n; i++) {
    i == n ? cout << a[i] << endl : cout << a[i] << " ";
  }
  return 0;
}
