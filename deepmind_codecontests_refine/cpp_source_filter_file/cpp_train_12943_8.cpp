#include <bits/stdc++.h>
using namespace std;
long long ax(long long n) {
  if (n < 12) {
    long long s = 0;
    for (int i = (1); i <= (n); ++i) s ^= i;
    return s;
  }
  long long a = (n - 12) / 4 * 4 + 1;
  long long s = 1;
  for (long long i = a + 1; i <= n; ++i) s ^= i;
  return s;
}
int main() {
  int n;
  long long a, b;
  cin >> n;
  long long s = 0;
  for (int i = (0); i < (n); ++i) {
    cin >> a >> b;
    s ^= ax(b - 1) ^ ax(b + a - 1);
  }
  cout << (s ? "tolik" : "bolik") << endl;
}
