#include <bits/stdc++.h>
using namespace std;
long long sumOfDigits(long long n) {
  long long sum = 0;
  while (n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long> a;
  long long n;
  cin >> n;
  long long nmax = 2e9 + 1;
  for (long long i = n; nmax >= n; i--) {
    nmax = i + sumOfDigits(i);
    if (nmax == n) a.push_back(i);
  }
  int az = (a).size();
  cout << az << '\n';
  for (int i = az - 1; i >= 0; i--) cout << a[i] << '\n';
  return 0;
}
