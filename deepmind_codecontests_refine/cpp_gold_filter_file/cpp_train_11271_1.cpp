#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
vector<bool> prime(10000005, true);
void sieveOfEratosthenes() {
  for (int i = 2; i <= sqrt(10000005); ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= 10000005; j += i) {
        prime[j] = false;
      }
    }
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long int p = sqrt(n);
  for (int i = 5; i <= p; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string str;
    cin >> str;
    long long int i = 0;
    while (i < n) {
      cout << str[n - 1];
      i++;
    }
    cout << endl;
  }
  return 0;
}
