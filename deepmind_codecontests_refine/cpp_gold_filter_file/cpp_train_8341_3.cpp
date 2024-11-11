#include <bits/stdc++.h>
using namespace std;
long long a1[1048576] = {0};
long long a2[1048576] = {0};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) a[i] ^= a[i - 1];
    if (i % 2)
      a1[a[i]]++;
    else
      a2[a[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < 1048576; ++i) {
    ans += ((a1[i] * (a1[i] - 1)) / 2);
    ans += ((a2[i] * (a2[i] - 1)) / 2);
  }
  ans += a1[0];
  cout << ans << "\n";
  return 0;
}
