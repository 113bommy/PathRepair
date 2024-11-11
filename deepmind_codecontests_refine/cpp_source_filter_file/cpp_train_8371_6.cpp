#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1000000007;
const double eps = 1e-7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
char str[maxn];
int main() {
  cin >> str;
  int len = strlen(str);
  int sum = 0;
  int ans = 1;
  for (int i = 1; i < len; i++) {
    if (str[i] == str[i - 1])
      ans++;
    else {
      if (ans % 2 == 0) sum++;
      ans = 1;
    }
  }
  cout << sum << endl;
  return 0;
}
