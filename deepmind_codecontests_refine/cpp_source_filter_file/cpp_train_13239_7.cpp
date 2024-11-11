#include <bits/stdc++.h>
using namespace std;
long long power(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base);
    base = (base * base);
    exp /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long n = s.length();
  long long n1 = n;
  long long cnt = 0;
  for (long long i = 0; i < n1; i++) {
    if (s[i] == '1') {
      cnt++;
    }
  }
  if (cnt == 1) {
    n--;
  }
  if (n % 2 == 0) {
    cout << n / 2 << "\n";
  } else {
    cout << n / 2 + 1 << "\n";
  }
  return 0;
}
