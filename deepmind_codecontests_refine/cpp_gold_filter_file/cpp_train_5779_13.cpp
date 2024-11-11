#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
bool p[N + 10];
int s[N + 10];
bool isprime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}
void pre(int n) {
  memset(p, true, sizeof(p));
  p[0] = p[1] = false;
  for (int i = 2; i * i <= n; ++i)
    if (p[i]) {
      for (int j = i << 1; j <= n; j += i) p[j] = false;
    }
  for (int i = 2; i <= n; ++i)
    if (p[i])
      for (int j = i; i + j <= n; ++j)
        if (p[j]) s[i + j] = i;
}
int main() {
  pre(N);
  int n;
  cin >> n;
  if (isprime(n)) {
    cout << 1 << endl;
    cout << n << endl;
    return 0;
  }
  for (int i = 1; i <= N; ++i)
    if (p[i] && isprime(n - i)) {
      cout << 2 << endl;
      cout << i << ' ' << n - i << endl;
      return 0;
    }
  for (int i = 1; i <= N; ++i)
    if (s[i] && isprime(n - i)) {
      cout << 3 << endl;
      cout << s[i] << ' ' << i - s[i] << ' ' << n - i << endl;
      return 0;
    }
}
