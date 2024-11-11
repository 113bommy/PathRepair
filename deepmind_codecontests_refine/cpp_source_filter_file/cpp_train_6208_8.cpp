#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;
const long long MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
int main() {
  int ar[6];
  for (long long i = 0; i < 6; i++) cin >> ar[i];
  sort(ar, ar + 6);
  do {
    int a = 0, b = 0;
    for (long long j = 1; j < 6; j++) {
      a = 0, b = 0;
      for (long long i = 0; i < j; i++) a += ar[i];
      for (long long i = j; i < 6; i++) b += ar[i];
      if (a == b) {
        cout << "YES\n";
        return 0;
      }
    }
  } while (next_permutation(ar, ar + 6));
  cout << "NO\n";
  return 0;
}
