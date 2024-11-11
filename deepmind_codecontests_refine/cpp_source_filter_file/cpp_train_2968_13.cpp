#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  bool prime[1000001];
  vector<int> primes;
  int end = 1000000;
  for (long long i = 1; i <= (int)end; i++) {
    prime[i] = 1;
  }
  prime[1] = 0;
  for (long long i = 1; i <= (int)end; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (long long j = i * 2; j <= end; j += i) {
        prime[j] = 0;
      }
    }
  }
  vector<int> palindromes;
  bool palindrome[1000001];
  for (long long i = 1; i <= (int)end; i++) {
    long long j = i;
    vector<int> sk;
    while (j != 0) {
      sk.push_back(j % 10);
      j /= 10;
    }
    bool fail = 0;
    for (long long j = 0; j < (int)sk.size(); j++) {
      if (sk[j] != sk[sk.size() - j - 1]) fail = 1;
    }
    if (!fail) {
      palindrome[i] = 1;
      palindromes.push_back(i);
    } else
      palindrome[i] = 0;
  }
  int smallerpalindromes = 0;
  vector<int> forprimes;
  int curprime = 0;
  while (true) {
    bool fail = 0;
    while (palindromes[smallerpalindromes] < primes[curprime]) {
      smallerpalindromes++;
      if (smallerpalindromes == palindromes.size()) fail = 1;
      if (fail) break;
    }
    if (fail) break;
    forprimes.push_back(smallerpalindromes);
    curprime++;
    if (curprime == primes.size()) break;
  }
  long long p, q;
  cin >> p >> q;
  long long ans = 0;
  for (long long i = 0; i < (int)forprimes.size(); i++) {
    if (i * q <= forprimes[i] * p) ans = primes[i] - 1;
  }
  if (ans != 0)
    cout << ans;
  else
    cout << "Palindromic tree is better than splay tree";
  return 0;
}
