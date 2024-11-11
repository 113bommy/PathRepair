#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long p = 2;
  for (long long i = 1; i <= n; i++) {
    cout << (i * i * (i + 1) * (i + 1) - p) / i << endl;
    p = i * (i + 1);
  }
  return 0;
}
