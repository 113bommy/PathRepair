#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long n = 0;
  for (long long i = 1; i <= a; i++) n = n * 2 + 1;
  if (b > n / 2 + 1) b = n - b + 1;
  while (b != n / 2 + 1) {
    a--;
    n /= 2;
    if (b > n / 2 + 1) b = n - b + 1;
  }
  cout << a << endl;
  return 0;
}
