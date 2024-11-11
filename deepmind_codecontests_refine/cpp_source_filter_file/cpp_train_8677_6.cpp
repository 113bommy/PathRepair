#include <bits/stdc++.h>
using namespace std;
int main() {
  int sieve[1000001] = {0};
  vector<long int> prime;
  for (long int i = 2; i < 1000001; i++) {
    if (sieve[i] == 0) {
      prime.push_back(i);
      int j = 1;
      while (j * i < 1000001) {
        sieve[i * j] = 1;
        j++;
      }
    }
  }
  set<long long int> pr;
  std::set<long long int>::iterator it;
  for (int i = 0; i < prime.size(); i++) pr.insert(prime[i] * prime[i]);
  int n;
  cin >> n;
  while (n--) {
    long long x;
    cin >> x;
    if (pr.count(x))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
