#include <bits/stdc++.h>
using namespace std;
vector<long long> fib(100002);
long long m = 1000000007;
void filll() {
  fib[0] = 1;
  fib[1] = 1;
  for (long long i = 2; i <= 100000; i++)
    fib[i] = (fib[i - 1] % m + fib[i - 2] % m) % m;
}
int main() {
  filll();
  long long n, mi;
  cin >> n >> mi;
  long long ans = ((2 * fib[n]) % m + (2 * fib[mi]) % m - 2) % m;
  cout << ans;
  return 0;
}
