#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modl(const long long input, const long long ceil) {
  return input >= ceil ? input % ceil : input;
}
bool myfn(int i, int j) { return i < j; }
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  char str[105];
  cin >> str;
  long long n = strlen(str);
  long long f = 0;
  for (long long i = 1; i <= n - 2; ++i)
    if (str[i] != str[i - 1] && str[i] != str[i + 1] &&
        str[i - 1] != str[i + 1] && str[i] != '.' && str[i - 1] != '.' &&
        str[i + 1] != '.')
      f = 1;
  if (f)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
  return (0);
}
