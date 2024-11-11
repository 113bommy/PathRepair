#include <bits/stdc++.h>
using namespace std;
long long quickPow(long long x, long long n, long long p) {
  long long res = 1, bas = x;
  while (n) {
    if (n & 1) res = res * bas % p;
    bas = bas * bas % p;
    n >>= 1;
  }
  return res;
}
bool isPrime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return 0;
  return 1;
}
long long ans;
int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
void dfs(int dep, int num, int temp, int up, int n) {
  if (num > n || dep >= 16) return;
  if (num == n && temp < ans) {
    ans = temp;
    return;
  }
  for (int i = 1; i <= up; i++) {
    if (temp / p[dep] > ans) break;
    dfs(dep + 1, num * (i + 1), temp = temp * p[dep], i, n);
  }
}
int main() {
  int n;
  cin >> n;
  ans = 1e18;
  dfs(0, 1, 1, 64, n);
  cout << ans << endl;
  return 0;
}
