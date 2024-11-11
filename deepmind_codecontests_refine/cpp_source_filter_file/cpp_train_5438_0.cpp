#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int sum = 0;
  bool b = false;
  for (int i = 2; i < s.length(); i++) {
    sum = 0;
    sum += (s[i - 1] - 'A');
    sum += (s[i - 2] - 'A');
    if ((char)(sum % 26 + 'A') == s[i]) {
      b = true;
    }
  }
  if (b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
