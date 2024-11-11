#include <bits/stdc++.h>
using namespace std;
std::vector<long long int> v2;
void sieve(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) v2.push_back(p);
}
int main() {
  long long int n = 0;
  long long int temp = 0;
  double temp2 = 0.00;
  std::vector<long long int> v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    v.push_back(temp);
  }
  sieve(100000);
  for (int i = 0; i < v.size(); ++i) {
    temp2 = sqrt(v[i]);
    if (binary_search(v2.begin(), v2.end(), temp2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
