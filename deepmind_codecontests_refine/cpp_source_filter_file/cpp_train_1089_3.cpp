#include <bits/stdc++.h>
using namespace std;
long long f(long long n, long long h) {
  if (!h) return 0;
  long long N2 = 1 << (h - 1);
  if (n <= N2) return f(N2 - n + 1, h - 1) + 1;
  return f(n - N2, h - 1) + 2 * N2;
}
int main() {
  ios::sync_with_stdio(0);
  long long n, h;
  cin >> h >> n;
  cout << f(n, h) << endl;
}
