#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long x = 2;
  for (long long i = 1; i <= n; i++) {
    cout << i * (i + 1) * (i + 1) - x / i << endl;
    x = i * (i + 1);
  }
  return 0;
}
