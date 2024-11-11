#include <bits/stdc++.h>
using namespace std;
long long ret = 0;
long long La, Ra, Ta;
long long Lb, Rb, Tb;
long long GCD = 0;
pair<long long, long long> gcd(long long a, long long b) {
  if (b == 0) {
    GCD = a;
    return {1, 0};
  }
  pair<long long, long long> nxt = gcd(b, a % b);
  long long x = nxt.first;
  long long y = nxt.second;
  long long k = a / b;
  return {y, x - k * y};
}
int main() {
  cout << setprecision(10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> La >> Ra >> Ta;
  cin >> Lb >> Rb >> Tb;
  pair<long long, long long> eq = gcd(Ta, Tb);
  long long L0 = La % GCD, R0 = L0 + (Ra - La);
  long long L1 = Lb % GCD, R1 = L1 + (Rb - Lb);
  La = L0;
  Ra = R0;
  Lb = L1;
  Rb = R1;
  for (long long offA = 0; offA <= 1; offA++)
    for (long long offB = 0; offB <= 1; offB++) {
      long long N_Ra = Ra + offA * Ta;
      long long N_La = La + offA * Ta;
      long long N_Rb = Rb + offB * Tb;
      long long N_Lb = Lb + offB * Tb;
      ret = max(ret, min(N_Ra, N_Rb) - max(N_La, N_Lb) + 1);
    }
  cout << ret << '\n';
  return 0;
}
