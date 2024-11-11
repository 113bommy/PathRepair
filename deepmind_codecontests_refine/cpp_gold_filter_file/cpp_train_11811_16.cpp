#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, numero, S = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> numero;
    S = S + numero;
  }
  cout << n * (n + 1) / 2 - S;
  return 0;
}
