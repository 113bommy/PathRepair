#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, x = 0;
  cin >> a;
  for (long long i = 1; i < a + 1; i++) {
    x += (1 << i);
  }
  cout << x;
  return 0;
}
