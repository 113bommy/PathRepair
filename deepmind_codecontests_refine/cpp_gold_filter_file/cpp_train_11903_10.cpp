#include <bits/stdc++.h>
using namespace std;
const int N = 2000210;
inline int scan() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x;
}
inline long long int gcd(long long int a, long long int b) {
  long long int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
string s;
long long int k;
long long int f[N];
long long int ct = 0;
int main() {
  f[0] = 1;
  cin >> k;
  cin >> s;
  for (long long int i = 0; i < s.length(); i++) {
    ct += s[i] == '1';
    f[ct]++;
  }
  long long int ans = 0;
  for (long long int i = k; i <= ct; i++) {
    if (k == 0) {
      ans += f[i] * (f[i] - 1) / 2;
    } else {
      ans += f[i] + f[i] * (f[i - k] - 1);
    }
  }
  cout << ans << endl;
  return 0;
}
