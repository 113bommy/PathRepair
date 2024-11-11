#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000000007;
const int Nmax = 110;
long long Now, N, Pwr;
char X[Nmax];
int main() {
  cin >> X;
  N = strlen(X);
  Pwr = 2LL;
  Now = X[N - 1] - '0';
  for (int i = N - 2; i >= 0; --i) {
    Pwr = (1LL * Pwr * 2LL) % Mod;
    Now = (1LL * Now * 2LL) % Mod;
    if (X[i] == '1') Now = (1LL * Now + 1LL * Pwr) % Mod;
  }
  cout << Now << '\n';
}
