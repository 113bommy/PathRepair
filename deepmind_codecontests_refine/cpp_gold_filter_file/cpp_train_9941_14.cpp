#include <bits/stdc++.h>
using namespace std;
const double h = 1e-6;
const int MAX_ = 200005;
inline long long int mul(long long int a, long long int b) {
  return (a * 1ll * b) % 1000000007;
}
inline long long int sub(long long int a, long long int b) {
  long long int c = a - b;
  if (c < 0) c += 1000000007;
  return c;
}
inline long long int add(long long int a, long long int b) {
  long long int c = a + b;
  if (c > 1000000007) c -= 1000000007;
  return c;
}
long long int sqr(long long int x) { return x * x; }
long long int ncr[3050][3050];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 3050; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || j == 0)
        ncr[i][j] = 1;
      else
        ncr[i][j] = add(ncr[i - 1][j - 1], ncr[i - 1][j]);
    }
  }
  int k;
  cin >> k;
  long long int val;
  long long int ans = 1;
  int count = 0;
  for (long long int i = 0; i < k; i++) {
    cin >> val;
    ans = mul(ans, ncr[count + val - 1][val - 1]);
    ans %= 1000000007;
    count += val;
  }
  cout << ans;
  return 0;
}
