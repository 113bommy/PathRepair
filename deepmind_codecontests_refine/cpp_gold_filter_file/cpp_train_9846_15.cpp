#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  long long a, c = 0, sum = 0;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    if (a > c) c = a;
  }
  cout << (n * c) - sum << endl;
  return 0;
}
