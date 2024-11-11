#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long a[(101)] = {};
int main() {
  long long n = read();
  for (int i = 1; i <= n; i++) {
    int p = read();
    a[p] = 1;
  }
  long long ans = 0;
  for (int i = 1; i <= 100; i++)
    if (a[i]) {
      ++ans;
      for (int j = 2 * i; j <= 100; j += i) a[j] = 0;
    }
  cout << ans;
  return 0;
}
