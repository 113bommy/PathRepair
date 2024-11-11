#include <bits/stdc++.h>
const long long N = 1200005;
const long long MOD = 1000000009L;
using namespace std;
long long p;
long long q;
int cntPrime[N] = {0};
int isPrime[N] = {1};
int cntPalindrome[N] = {0};
string notExist = "Palindromic tree is better than splay tree";
bool isPalindrome(int i) {
  string s = to_string(i);
  int r = s.length();
  int l = 0;
  r--;
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> p >> q;
  for (int i = 0; i < N; i++) isPrime[i] = 1;
  isPrime[0] = isPrime[1] = 0;
  for (long long i = 1; i < N; i++) {
    if (isPrime[i] == 1) {
      for (long long j = i * i; j < N; j += i) {
        isPrime[j] = 0;
      }
    }
    cntPrime[i] = isPrime[i];
    if (i > 1) {
      cntPrime[i] += cntPrime[i - 1];
    }
  }
  for (int i = 1; i < N; i++) {
    if (isPalindrome(i)) {
      cntPalindrome[i] = 1;
    } else {
      cntPalindrome[i] = 0;
    }
    if (i > 0) {
      cntPalindrome[i] += cntPalindrome[i - 1];
    }
  }
  long long answer = -1;
  for (int i = 0; i < N; i++) {
    if ((q * cntPrime[i]) <= (p * cntPalindrome[i])) {
      answer = i;
    }
  }
  if (answer == -1) {
    cout << notExist << "\n";
  } else {
    cout << answer << "\n";
  }
}
