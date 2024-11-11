#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 1;
int n, t;
bool isPrime[MAXN];
long long P, Q, primes, palindromes;
bool isPalindrome(int num) {
  vector<int> A;
  while (num) {
    A.push_back(num % 10);
    num /= 10;
  }
  int left = 0, right = A.size() - 1;
  while (left < right) {
    if (A[left] != A[right]) return false;
    left++, right--;
  }
  return true;
}
int main() {
  cin >> P >> Q;
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for (int i = 2; i < MAXN; i++)
    if (isPrime[i])
      for (int j = i + i; j < MAXN; j += i) isPrime[j] = false;
  int ans = -1;
  for (int i = 1; i < MAXN; i++) {
    primes += isPrime[i] == true;
    palindromes += isPalindrome(i);
    if (Q * primes <= P * palindromes) ans = i;
  }
  if (ans == -1)
    printf("Palindromic tree is better than splay tree\n");
  else
    printf("%d\n", ans);
  return 0;
}
