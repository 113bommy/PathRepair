#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
template <class T>
T power(T a, long long int n) {
  T res = 1;
  while (n > 0) {
    if (n % 2) res = res * a;
    a = a * a, n = n / 2;
  }
  return res;
}
vector<long long int> arr;
;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) arr.push_back(p);
}
int main() {
  SieveOfEratosthenes(100000);
  long long int n, m;
  cin >> n >> m;
  long long int mat[n + 1][m + 1];
  long long int ansr = INT_MAX, ansc = INT_MAX;
  for (int i = 0; i < n; i++) {
    long long int sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      long long int a = mat[i][j];
      long long int ind = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
      sum += arr[ind] - a;
    }
    ansr = min(ansr, sum);
  }
  for (int i = 0; i < m; i++) {
    long long int sum = 0;
    for (int j = 0; j < n; j++) {
      long long int a = mat[j][i];
      long long int ind = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
      sum += arr[ind] - a;
    }
    ansc = min(ansc, sum);
  }
  cout << min(ansc, ansr);
}
