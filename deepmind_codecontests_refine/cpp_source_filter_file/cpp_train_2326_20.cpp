#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int d;
  cin >> d;
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int sum = 0;
  for (int i = 1; i < n; i++) sum += d - a[i];
  cout << sum;
}
