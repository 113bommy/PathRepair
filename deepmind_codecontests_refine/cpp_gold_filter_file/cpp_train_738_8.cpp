#include <bits/stdc++.h>
using namespace std;
long long int getsmall(long long int x) {
  for (long long int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return i;
  }
  return x;
}
int main() {
  long long int n;
  long long int count = 0;
  cin >> n;
  if (n == 0) return 0;
  if (n % 2 != 0) {
    n = n - getsmall(n);
    count++;
  }
  count = count + (n / 2);
  cout << count << endl;
  return 0;
}
