#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16 + 10;
const int N = 5e2 + 10;
int n, a[N];
long long check(long long low) {
  if (low == 0) return inf;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long gr = a[i] / low;
    long long rem = a[i] % low;
    if (rem > gr) return inf;
    long long n1 = gr - rem;
    ans += n1 / (low + 1);
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = inf;
  for (int i = 1; i * i <= a[1]; i++) {
    ans = min(ans, check(i));
    ans = min(ans, check(a[1] / i));
    ans = min(ans, check(a[1] / i - 1));
  }
  cout << ans;
}
