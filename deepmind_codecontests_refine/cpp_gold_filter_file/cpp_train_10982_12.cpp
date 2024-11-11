#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) { return a > b; }
class Compare {
 public:
  bool operator()(int a, int b) { return a > b; }
};
int mod(int a, int b) { return ((a % b) + b) % b; }
bool prime[5000];
vector<int> primes;
vector<long long> ans;
int n;
long long m;
void build_primes() {
  primes = vector<int>();
  for (int i = 0; i < 2000; i++) prime[i] = true;
  prime[0] = prime[1] = false;
  for (int i = 2; i <= 1010; i++)
    if (prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= 1010; j += i) prime[j] = false;
    }
}
int main() {
  build_primes();
  scanf("%d", &n);
  ans = vector<long long>();
  for (int i = 0; i < primes.size(); i++) {
    m = primes[i];
    if (m > n) break;
    for (int j = 0; j < 10; j++)
      if (m <= n) ans.push_back(m), m *= primes[i];
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%I64d ", ans[i]);
  return 0;
}
