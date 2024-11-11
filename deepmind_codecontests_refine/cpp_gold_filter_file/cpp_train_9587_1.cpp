#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
long long n, k;
long long Arr[N];
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> Arr[i];
  long long GCD = k;
  for (int i = 0; i < n; i++) GCD = gcd(GCD, Arr[i]);
  cout << k / GCD << '\n';
  for (int i = 0; i < k; i += GCD) cout << i << ' ';
  cout << '\n';
  return 0;
}
