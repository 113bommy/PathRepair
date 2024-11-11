#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool flag[1002];
void sieve() {
  for (int i = 2; i <= sqrt(1000); i++) {
    if (!flag[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j <= 1000; j += i) flag[j] = 0;
  }
}
bool isprime(int a) {
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return 0;
  return 1;
}
int get2primes(int a) {
  for (int i = 0; i < primes.size(); i++) {
    if (isprime(a - primes[i])) return primes[i];
  }
}
int main() {
  int n;
  memset(flag, 1, sizeof flag);
  sieve();
  cin >> n;
  vector<int> ans;
  if (isprime(n)) {
    ans.push_back(n);
  } else {
    int temp = n;
    while (!isprime(temp)) temp -= 2;
    ans.push_back(temp);
    n -= temp;
    if (isprime(n))
      ans.push_back(n);
    else {
      int lala = get2primes(n);
      ans.push_back(lala);
      ans.push_back(n - lala);
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
