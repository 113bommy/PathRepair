#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long INF = 2e18;
void print(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
set<int> mainset;
set<int> findPrimeFactors(int n) {
  set<int> primeFactors;
  while (n % 2 == 0) primeFactors.insert(2), n = n / 2;
  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      primeFactors.insert(i);
      n = n / i;
    }
  }
  if (n > 2) primeFactors.insert(n);
  return primeFactors;
}
bool isPrime(int n) {
  if (n == 2 or n == 3) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) {
    int n;
    cin >> n;
    int z;
    cin >> z;
    int a[n];
    for (int i = 0; i < (n); i++) cin >> a[i];
    sort(a, a + n);
    int now = 1;
    int ans = 0;
    for (int i = 0; i < (n / 2); i++) {
      while (now < n and a[now] - a[i] < z) now++;
      if (now >= n) break;
      ans++, now++;
    }
    cout << ans;
  }
}
