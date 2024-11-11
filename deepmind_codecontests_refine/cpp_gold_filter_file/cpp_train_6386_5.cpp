#include <bits/stdc++.h>
using namespace std;
long long f(long long a) {
  long long cnt = 0, i;
  if (a == 2) return 1;
  for (i = 2; i * i < a; i++) {
    if (a % i == 0) cnt += 2;
  }
  if (i * i == a) cnt++;
  return cnt;
}
vector<long long> a(1001);
long long powM(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans % m;
}
long long g(long long a, long long n) {
  if (a < 0)
    return ((a % n) + n) % n;
  else
    return a % n;
}
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    a[i] = min(a[i], max(a[i - 1], a[i - 2]));
  }
  cout << a[n] << "\n";
  return 0;
}
