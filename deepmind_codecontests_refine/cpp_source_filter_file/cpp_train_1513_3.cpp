#include <bits/stdc++.h>
using namespace std;
void PrintArray(const vector<long long int> &arr) {
  for (int i = 0; i < (int)arr.size(); i++) cout << arr[i] << " ";
  cout << endl;
}
void SieveOfEratosthenes(int n) {
  vector<bool> prime(n + 1, 0);
  prime[0] = 0;
  prime[1] = 0;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  ;
  int n;
  long long unsigned int t;
  cin >> n >> t;
  t--;
  long double r = 1.000000011;
  long double x = pow(r, t);
  x *= n;
  printf("%0.100Lf\n", x);
  return 0;
}
