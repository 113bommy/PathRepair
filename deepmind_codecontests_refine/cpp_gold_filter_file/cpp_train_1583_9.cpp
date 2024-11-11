#include <bits/stdc++.h>
using namespace std;
bool isPrime[2001];
vector<int> primes;
void gen() {
  memset(isPrime, true, sizeof(isPrime));
  for (int i = 2; i <= 2000; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= 2000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}
int main() {
  gen();
  string s;
  cin >> s;
  set<int> nums;
  int l = --upper_bound(primes.begin(), primes.end(), s.size() / 2) -
          primes.begin();
  int r =
      --upper_bound(primes.begin(), primes.end(), s.size()) - primes.begin();
  for (int i = l + 1; i <= r; i++) {
    nums.insert(primes[i]);
  }
  nums.insert(1);
  int diff = r - l + 1;
  int same = s.size() - diff;
  for (char c = 'a'; c <= 'z'; c++) {
    if (count(s.begin(), s.end(), c) >= same) {
      printf("YES\n");
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != c) {
          for (int p : nums) {
            if (s[p - 1] == c) {
              swap(s[p - 1], s[i]);
              break;
            }
          }
        }
      }
      cout << s << '\n';
      return 0;
    }
  }
  printf("NO\n");
}
