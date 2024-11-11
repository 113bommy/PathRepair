#include <bits/stdc++.h>
using namespace std;
unsigned long long n, k, ans = -1;
void check(unsigned long long d) {
  unsigned long long s = k * (k - 1) / 2;
  s *= d;
  if (n > s && n - s > (k - 1) * d) {
    ans = max(ans, d);
  }
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (unsigned long long i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      check(i);
      check(n / i);
    }
  }
  if (ans == -1) {
    cout << -1;
    return 0;
  }
  for (unsigned long long i = 1; i < k; ++i) {
    cout << i * ans << " ";
  }
  unsigned long long s = k * (k - 1) / 2;
  cout << n - s * ans;
  return 0;
}
