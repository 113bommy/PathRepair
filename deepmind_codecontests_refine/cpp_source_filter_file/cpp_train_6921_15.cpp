#include <bits/stdc++.h>
using namespace std;
ifstream in("input.in");
ofstream out("output.out");
const long long nmx = 200005;
int main() {
  ios::sync_with_stdio(0);
  long long n, a[nmx];
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long ans = 0;
  long long s = 0;
  for (long long i = 1; i <= n; ++i) {
    if (s <= a[i]) ++ans;
    s += a[i];
  }
  cout << ans;
  return 0;
}
