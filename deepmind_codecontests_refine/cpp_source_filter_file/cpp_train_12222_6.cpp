#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007;
long long FastPower(long long x, long long y);
int main() {
  string a;
  cin >> a;
  long long k;
  cin >> k;
  long long n = a.size();
  long long Answer = 0;
  for (long long i = n - 1; i >= 0; i--)
    if (a[i] == '0' || a[i] == '5')
      Answer =
          (Answer + (FastPower(2, i) * ((FastPower(2, n * k) - 1 + Mod) % Mod) *
                     FastPower(FastPower(2, n) - 1, Mod - 2)) %
                        Mod) %
          Mod;
  cout << Answer;
}
long long FastPower(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long Res = FastPower(x, y >> 1) % Mod;
  Res = (Res * Res) % Mod;
  if (y & 1) Res = (Res * x) % Mod;
  return Res;
}
