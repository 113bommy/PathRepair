#include <bits/stdc++.h>
using namespace std;
long long int const lac = 100000;
long long int modmul(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int modadd(long long int a, long long int b) {
  return (((a % 1000000007) + (b % 1000000007))) % 1000000007;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
class comp {
 public:
  bool operator()(int a, int b) const { return a > b; }
};
bool compa(int a, int b) { return a > b; }
void solve(long long int t1) {
  long long int n;
  cin >> n;
  vector<long long int> arr(n + 1);
  for (long long int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  vector<long long int> prefix(n + 1, 0);
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] ^ i;
    ans ^= arr[i];
  }
  if (n == 1) {
    cout << ans << "\n";
    return;
  }
  for (long long int i = 1; i <= n - 1; i++) {
    long long int temp = (n) / (i + 1);
    long long int rem = n % i;
    if (temp & 1) {
      ans ^= prefix[i];
    }
    ans ^= prefix[rem];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  for (long long int i = 1; i <= t; i++) {
    solve(t);
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
