#include <bits/stdc++.h>
using namespace std;
long long n, minn = 1e18;
long long a[1010];
int main() {
  long long n, s, sum = 0;
  cin >> n >> s;
  for (long long i = 1; i <= n; ++i)
    cin >> a[i], minn = min(minn, a[i]), sum += a[i];
  if (s <= sum - n * minn) {
    cout << minn << endl;
    return 0;
  }
  if (minn - (s - (sum - n * minn) + n - 1) / n) {
    cout << (minn - (s - sum + n * minn + n - 1) / n) << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
