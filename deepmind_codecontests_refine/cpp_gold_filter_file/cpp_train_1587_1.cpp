#include <bits/stdc++.h>
using namespace std;
void readInput() {}
int F[500011];
int main() {
  readInput();
  int n;
  cin >> n;
  int primes = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) F[j] = i;
  }
  sort(F + 2, F + n + 1);
  for (int i = 2; i <= n; i++) {
    cout << F[i] << " ";
  }
  return 0;
}
