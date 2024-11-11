#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a;
  cin >> n;
  a = 1;
  for (int i = 1; i < n; i++) {
    a *= i;
  }
  cout << a / n * 2;
  return 0;
}
