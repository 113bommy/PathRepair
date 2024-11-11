#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long n = a + b + 1;
  for (long long i = b + 1; i <= n; i++) {
    cout << i << " ";
  }
  for (long long i = 1; i <= b; i++) {
    cout << i << " ";
  }
}
