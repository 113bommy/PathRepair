#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535;
long long powi(long long base, int p) {
  long long res = 1;
  while (p--) res *= base;
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool is_vowel(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << "+------------------------+\n";
  cout << '|';
  cout << (k > 0 ? '0' : '#') << '.';
  for (int i = 1; i <= 10; i++)
    cout << ((k - 4 + 2) / 3 >= i ? '0' : '#') << '.';
  cout << "|D|)\n";
  cout << '|';
  cout << (k > 1 ? '0' : '#') << '.';
  for (int i = 1; i <= 10; i++)
    cout << ((k - 4 + 1) / 3 >= i ? '0' : '#') << '.';
  cout << "|.|\n";
  cout << '|';
  cout << (k > 2 ? '0' : '#') << '.';
  for (int i = 1; i <= 10; i++) cout << "..";
  cout << "..|\n";
  cout << '|';
  cout << (k > 3 ? '0' : '#') << '.';
  for (int i = 1; i <= 10; i++) {
    cout << ((k - 4) / 3 >= i ? '0' : '#') << '.';
  }
  cout << "|.|)\n";
  cout << "+------------------------+";
  return 0;
}
