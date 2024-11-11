#include <bits/stdc++.h>
using namespace std;
int main() {
  long long unsigned n, acum = 1;
  cin >> n;
  for (int i = 2; i < sqrt(n); i++)
    if (n % i == 0) {
      acum *= i;
      while (n % i == 0) n /= i;
    }
  cout << acum * n << endl;
  return 0;
}
