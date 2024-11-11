#include <bits/stdc++.h>
using namespace std;
int mo(int n) {
  int p = 1;
  while (n--) p = p * 2;
  return p;
}
int main() {
  long long int n;
  cin >> n;
  for (int i = sqrt(n); i >= 1; i++) {
    if (n % i == 0) {
      cout << i << " " << n / i << endl;
      return 0;
    }
  }
  return 0;
}
